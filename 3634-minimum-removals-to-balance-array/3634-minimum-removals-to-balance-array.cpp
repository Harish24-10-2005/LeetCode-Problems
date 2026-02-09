class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--){
            int temp = n - i - 1;
            int num = (nums[i] + k -1)/k;
            int idx = lower_bound(nums.begin(),nums.end(),num) - nums.begin();
            ans = min(ans,temp + idx);
        }
        return ans;
    }
};