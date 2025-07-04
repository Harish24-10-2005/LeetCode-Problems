class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int tar) {
        int to = accumulate(nums.begin(),nums.end(),0);
        if ((tar + to) % 2 != 0 || tar > to) return 0;
        int n = nums.size();

        int t = (to + tar)/2;
        vector<vector<int>>dp(n,vector<int>(t+1,0));

        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] =1;

        if(nums[0] != 0 && nums[0]<= t) dp[0][nums[0]] = 1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=t;j++)
            {
                int notPick = dp[i - 1][j];
                int pick = 0;
                if (nums[i] <= j)
                    pick = dp[i - 1][j - nums[i]];
                dp[i][j] = pick + notPick;
            }
        }
        return dp[n-1][t];
    }
};