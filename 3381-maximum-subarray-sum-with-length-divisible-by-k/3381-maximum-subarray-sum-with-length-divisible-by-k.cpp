class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>pre(n,0),dp(n,LLONG_MIN);

        pre[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i] = (long long)pre[i-1] + nums[i];
            // cout<<pre[i]<<endl;
        }
        long long ans = INT_MIN;
        for(int i=0;i<=n-k;i++)
        {
            long long summ = pre[i+k-1];
            if(i-1>=0) summ-=pre[i-1];
            if(i-k >= 0)
            {
                // cout<<dp[i-k]<<endl;
                if((dp[i-k] + summ) > summ)
                {
                    dp[i] = dp[i-k] + summ;
                }
                else dp[i] = summ;
            }
            else dp[i] = summ;
        }
        return *max_element(dp.begin(),dp.end());
    }
};