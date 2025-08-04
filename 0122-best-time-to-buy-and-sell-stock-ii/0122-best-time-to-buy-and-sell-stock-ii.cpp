class Solution {
// int rec(int i,int buy,vector<int>&prices)
// {
//     if(i == prices.size()-1)
//     {
//         if(buy) return 0;
//         return prices[prices.size()-1];
//     }
//     int p = 0;
//     if(buy)
//     {
//         p = max(-prices[i] + rec(i+1,0,prices) , rec(i+1,1,prices));
//     }
//     else
//     {
//         p = max(prices[i] + rec(i+1,1,prices), rec(i+1,0,prices));
//     }
//     return p;
// }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,0));
        int take = -prices[0];
        int not_take = 0;

        // dp[0][1] = -prices[0];
        // dp[0][0] = 0;
        for(int i=1;i<n;i++)
        {
            for(int j= 0;j<2;j++)
            {
                if(j)
                {
                    take = max(-prices[i]+not_take ,take);
                }
                else
                {
                    not_take = max(prices[i]+take ,not_take);
                }
            }
        }
        return max(take,not_take);
    }
};