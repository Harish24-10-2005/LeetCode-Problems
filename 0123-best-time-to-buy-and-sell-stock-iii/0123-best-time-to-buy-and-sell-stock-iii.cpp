class Solution {
private: 
    int rec(int i,int buy,int n,int cnt,vector<int>&p,vector<vector<vector<int>>>&dp)
    {
        if(i == n || cnt == 2) return 0;
        if(dp[i][buy][cnt] !=-1) return dp[i][buy][cnt];
        int pr = 0;
        if(buy)
        {
            pr = max(-p[i] + rec(i+1,0,n,cnt,p,dp),rec(i+1,1,n,cnt,p,dp));
        }
        else
        {
            pr = max(p[i] + rec(i+1,1,n,cnt+1,p,dp),rec(i+1,0,n,cnt,p,dp));
        }
        return dp[i][buy][cnt] = pr;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(0,1,prices.size(),0,prices,dp);
    }
};