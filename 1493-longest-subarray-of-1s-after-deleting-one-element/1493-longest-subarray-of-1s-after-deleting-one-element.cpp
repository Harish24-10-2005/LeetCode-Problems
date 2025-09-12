class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int summ = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            summ+=nums[i];
            while(summ < i - l)
            {
                summ-=nums[l];
                l++;
            }
            ans = max(ans, i - l);
        }
        return ans;
    }
};