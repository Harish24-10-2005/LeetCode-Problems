class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size();
        while(l<=r){
            int mid = l + (r-l)/2;
            int idx = lower_bound(nums.begin(),nums.end(),mid) - nums.begin();
            int len = nums.size() - idx;
            if(mid == len) return mid;
            if(len > mid) l = mid + 1;
            else r = mid -1;
        }
        return -1;
    }
};