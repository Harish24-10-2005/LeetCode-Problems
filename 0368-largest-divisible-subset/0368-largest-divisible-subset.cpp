class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(),nums.end());
        vector<int>dp(n);
        vector<int>hash(n,0);
        for(int i =0 ;i<n;i++)
        {
            hash[i] = i;
            for(int j=0;j<=i-1;j++)
            {
                if(nums[i]%nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] +1;
                    hash[i] = j;
                }
            }
        }
        int pre = 0;
        for(int i=0;i<n;i++)
        {
            if(dp[i] > dp[pre])
            {
                pre = i;
            }
        }
        vector<int>res;
        res.push_back(nums[pre]);
        while(hash[pre] != pre)
        {
            pre = hash[pre];
            res.push_back(nums[pre]);
        }
        return res;
    }
};