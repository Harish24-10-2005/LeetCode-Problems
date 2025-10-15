class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = 0;
        for(int i = 1;i<n;i++)
        {
            if(nums[i-1] < nums[i])
            {
                dp[i] = dp[i-1];
            }
            else
            {
                dp[i] = dp[i-1] + 1;
            }
        }
        // for(auto a:dp)
        // {
        //     cout<<a<<" ";
        // }
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            // if(dp[i-1] < dp[i])
            // {
            int l = lower_bound(dp.begin(),dp.end(),dp[i-1]) - dp.begin();
            int r = upper_bound(dp.begin(),dp.end(),dp[i]) - dp.begin();
            // cout<<"I = "<<i<<" r = "<<r<<" l = "<<l<<endl;
            ans = max(ans, min(r-i,i-l));
            // }
        }
        return ans;
    }
};