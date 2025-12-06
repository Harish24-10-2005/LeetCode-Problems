class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n >1 && nums[0] > nums[1]) return 0;
        if(n >1 && nums[n-2] < nums[n-1]) return n-1;
        int l = 1;
        int r = n-2;
        while(l <= r)
        {
            int mid = (r-l)/2 + l;
            if(nums[mid]> nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if(nums[mid] < nums[mid +1]) l = mid+1;
            else r = mid-1;
        }
        return 0;
    }
};