class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int summ = 0;
        int ans = 0;
        mpp[0] = 1;
        for(int i=0;i<n;i++)
        {
            summ+=nums[i];
            int r = (summ%k+k)%k;
            ans+=mpp[r];
            mpp[r]++;
        }
        return ans;
    }
};