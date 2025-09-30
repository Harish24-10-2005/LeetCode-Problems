class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n);
        dp[0] = nums;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                if(j+1 < dp[i-1].size()) dp[i].push_back((dp[i-1][j] + dp[i-1][j+1])%10);
            }
        }
        return dp[n-1][0]; 
    }
};