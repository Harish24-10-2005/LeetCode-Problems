class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int minn = prices[0];
        for(int i=1;i<n;i++)
        {
            ans = max(ans,prices[i]-minn);
            if(minn > prices[i]) minn = prices[i];
        }
        return ans;
    }
};