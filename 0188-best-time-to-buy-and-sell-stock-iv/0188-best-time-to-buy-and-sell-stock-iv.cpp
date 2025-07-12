class Solution {
    int rec(int i,int buy,int k,int n,vector<int>&p,vector<vector<vector<int>>>&dp)
    {
        if(k == 0) return 0;
        if(i == n-1)
        {
            if(buy) return 0;
            return p[n-1];
        }
        if(dp[i][buy][k] !=-1) return dp[i][buy][k];
        int ans = 0;
        if(buy)
        {   
            ans = max(-p[i]+rec(i+1,0,k,n,p,dp),rec(i+1,1,k,n,p,dp));
        }   
        else
        {
            ans = max(p[i] + rec(i+1,1,k-1,n,p,dp),rec(i+1,0,k,n,p,dp));
        }
        return dp[i][buy][k] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return rec(0,1,k,n,prices,dp);
    }
};