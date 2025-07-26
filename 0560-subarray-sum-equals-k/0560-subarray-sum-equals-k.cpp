class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt =0;
        int prefix_sum = 0;
        map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum+=nums[i];
            int remove = prefix_sum-k;
            cnt+=mpp[remove];
            mpp[prefix_sum]+=1;
        }
        return cnt;
    }
};