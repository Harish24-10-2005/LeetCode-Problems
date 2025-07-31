class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int summ = 0;
        int ans = 0;
        mpp[0] = 1;
        for(int i=0;i<n;i++)
        {
            summ+=nums[i];
            int r = summ - k;
            ans+=mpp[r];
            mpp[summ]++;
        }
        return ans;
    }
};