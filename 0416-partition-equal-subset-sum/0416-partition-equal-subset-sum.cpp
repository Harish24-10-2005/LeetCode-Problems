class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = 0;
        for(int a:nums) t+=a;
        if (t % 2 != 0) return false;
        int n = nums.size();
        vector<vector<bool>>dp(n,vector<bool>((t/2)+1,false));
        for(int j=0;j<n;j++)
        {
            dp[j][0] = true;
        }
        if(nums[0]<=t/2)
        {
            dp[0][nums[0]] = true;
        }
        for(int i=1;i<n;i++)
        {
            for(int tar=1;tar<=t/2;tar++)
            {
                bool ntake = dp[i-1][tar];
                bool take = false;
                if(nums[i]<=tar)
                {
                    take = dp[i-1][tar-nums[i]];
                }
                dp[i][tar] = take || ntake;
            }
        }
        return dp[n-1][t/2];
    }   
};