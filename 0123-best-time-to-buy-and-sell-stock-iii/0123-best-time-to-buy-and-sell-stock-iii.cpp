class Solution {
    int rec(int i,bool buy,int cnt,vector<int>p)
    {
        if(cnt == 2) return 0;
        if(i >= p.size()) return 0;

        int t = 0;
        if(buy)
        {
            t = max(-p[i] + rec(i+1,!buy,cnt,p) ,rec(i+1,buy,cnt,p));
        }
        else
        {
            t = max(p[i] + rec(i+1,!buy,cnt+1,p) ,rec(i+1,buy,cnt,p));
        }
        return t;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        dp[0][0][0] = 0;
        dp[0][1][0] = -prices[0];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                for(int k=0;k<2;k++)
                {
                    if(j)
                    {
                        dp[i][j][k] = max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else
                    {
                        dp[i][j][k] = max(prices[i] + dp[i+1][1][k+1],dp[i+1][0][k]);
                    }
                }
            }
        }
        // return rec(0,true,0,prices);
        return dp[0][1][0];
    }
};