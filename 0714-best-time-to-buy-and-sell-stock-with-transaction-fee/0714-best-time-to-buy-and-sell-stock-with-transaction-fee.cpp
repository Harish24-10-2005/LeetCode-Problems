class Solution {
    int rec(int i,int buy,int f,int n,vector<int>&p,vector<vector<int>>&dp)
    {
        if(i == n) return 0;
        // {
        //     if(buy) return 0;
        //     return p[n-1];
        // }
        if(dp[i][buy] != -1) return dp[i][buy];
        int ans = 0;
        if(buy)
        {
            ans = max(-p[i] + rec(i+1,0,f,n,p,dp),rec(i+1,1,f,n,p,dp));
        }
        else
        {
            ans = max(p[i] - f + rec(i+1,1,f,n,p,dp),rec(i+1,0,f,n,p,dp));
        }
        return dp[i][buy] = ans;
    }
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        int nt = 0;       
        int t = -p[0];
        for(int i =1;i<n;i++)
        {
            t = max(-p[i] + nt,t);
            nt = max(p[i] - fee +t,nt);
        }
        return max(nt,t);
    }
};