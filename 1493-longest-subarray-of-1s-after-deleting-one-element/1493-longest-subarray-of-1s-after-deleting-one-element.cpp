class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        int l = 0;
        int i = 0;
        while(i<n)
        {
            sum+=nums[i];
            // cout<<i<<endl;
            while(l<i && sum < i-l)
            {
                sum-=nums[l];
                l++;
            }
            ans = max(ans,i-l);
            i++;
        }
        return ans;
    }
};