class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<n/2;i++){
            int temp = nums[i] + nums[n-i-1];
            ans = max(ans,temp);
        }
        return ans;

    }
};