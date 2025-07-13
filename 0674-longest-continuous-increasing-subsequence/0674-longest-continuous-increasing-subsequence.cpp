class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxx = 1;
        int cur = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i] > nums[i-1])
            {
                cur++;
                maxx = max(maxx , cur);
            }
            else 
            {
                cur = 1;
            }
        }
        return maxx;
    }
};