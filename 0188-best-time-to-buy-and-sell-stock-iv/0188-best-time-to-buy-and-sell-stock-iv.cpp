class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                for(int cnt=0;cnt<k;cnt++)
                {
                    if(j)
                    {
                        dp[i][j][cnt] = max(-prices[i]+dp[i+1][0][cnt],dp[i+1][1][cnt]);
                    }
                    else
                    {
                        dp[i][j][cnt] = max(prices[i] + dp[i+1][1][cnt+1],dp[i+1][0][cnt]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};