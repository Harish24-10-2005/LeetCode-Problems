class Solution {
private:
    // int rec(int i,int j,vector<int>&nums)
    // {
    //     if(i == nums.size()) return 0;
    //     int t = 0;
    //     if(nums[i] > nums[j])
    //     {
    //         t = 1 + rec(i+1,i,nums);
    //     }
    //     int nt = rec(i+1,j,nums);
    //     return max(t,nt);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int res = 1; 
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i],1 + dp[j]);
                }
                res = max(res,dp[i]);
            }
        }
        return res;
    }
};