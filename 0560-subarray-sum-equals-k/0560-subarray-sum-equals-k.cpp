class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>mpp;
        int summ = 0;
        mpp[0] = 1;
        for(int i=0;i<n;i++)
        {
            summ+=nums[i];
            ans+=mpp[summ-k];
            mpp[summ]++;
        }
        return ans;
    }
};