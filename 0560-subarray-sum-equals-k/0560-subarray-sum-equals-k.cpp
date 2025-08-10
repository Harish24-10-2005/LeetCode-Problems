class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;  
        int n = nums.size();
        int ans = 0;
        int summ = 0;
        mpp[0]=1;
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