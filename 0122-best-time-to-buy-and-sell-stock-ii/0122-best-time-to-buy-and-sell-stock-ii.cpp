class Solution {
    // int rec(int i,bool buy,vector<int>p)
    // {
    //     if(i >= p.size())
    //     {
    //         // if(!buy) return p[p.size()-1];
    //         return 0;
    //     }
    //     int t = 0;
    //     if(buy)
    //     {
    //         t = max(-p[i] + rec(i+1,!buy,p),rec(i+1,buy,p));
    //     }
    //     else
    //     {
    //         t = max(p[i] + rec(i+1,!buy,p),rec(i+1,buy,p));
    //     }
    //     return t;
    // }
public:
    int maxProfit(vector<int>& prices) {
        // return rec(0,true,prices);
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        dp[0][0] = 0; 
        dp[0][1] = -prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0] = max(prices[i] + dp[i-1][1] , dp[i-1][0]);
            dp[i][1] = max(-prices[i] + dp[i-1][0], dp[i-1][1]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};