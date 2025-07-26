class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1 && target == nums[0]) return 0;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = ((r-l)/2)+l;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<nums[r])
            {
                if(target <= nums[r] && target > nums[mid])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid-1;
                }
            }
            else
            {
                if(target >= nums[l] && target < nums[mid])
                {
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};