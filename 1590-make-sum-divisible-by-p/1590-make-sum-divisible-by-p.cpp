class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long summ = 0;
        for(int i:nums)
        {
            summ+=i;
            // summ%=p;
        }
        summ%=p;
        unordered_map<int,int>mpp;
        summ %= p;
        if(summ == 0) return 0;
        int ans = INT_MAX;
        int t = 0;
        mpp[0] = -1;
        for(int i=0;i<n;i++)
        {
            t+=nums[i];
            t%=p;
            if(mpp.count(((t - summ) % p + p) % p))
            {
                ans = min(ans, i - mpp[((t - summ) % p + p) % p]);
            }
            mpp[t] = i;
        }
        return ans == INT_MAX  || ans == n? -1 : ans;
    }
};