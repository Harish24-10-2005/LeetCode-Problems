class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int temp = 0;
        int maxx = *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i] == maxx) temp++;
            else temp = 0;
            ans = max(temp,ans);
        }
        return ans;
    }
};