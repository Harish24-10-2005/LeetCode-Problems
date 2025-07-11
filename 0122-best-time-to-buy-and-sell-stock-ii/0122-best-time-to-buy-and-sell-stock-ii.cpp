class Solution {
int rec(int i,int buy,vector<int>&prices)
{
    if(i == prices.size()-1)
    {
        if(buy) return 0;
        return prices[prices.size()-1];
    }
    int p = 0;
    if(buy)
    {
        p = max(-prices[i] + rec(i+1,0,prices) , rec(i+1,1,prices));
    }
    else
    {
        p = max(prices[i] + rec(i+1,1,prices), rec(i+1,0,prices));
    }
    return p;
}
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        for(int i=1;i<n;i++)
        {
            for(int j= 0;j<2;j++)
            {
                if(j)
                {
                    dp[i][j] = max(-prices[i]+dp[i-1][0] , dp[i-1][1]);
                }
                else
                {
                    dp[i][j] = max(prices[i]+dp[i-1][1] ,dp[i-1][0]);
                }
            }
        }
        return max(dp[n-1][1],dp[n-1][0]);
    }
};