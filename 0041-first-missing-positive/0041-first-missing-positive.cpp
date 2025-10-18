class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        int i = 1;
        for(auto a:nums)
        {
            if(a != i)
            {
                return i;
            }
            i++;
        }
        return i;
    }
};