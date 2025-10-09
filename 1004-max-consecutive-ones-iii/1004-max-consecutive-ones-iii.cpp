class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int z  = 0;
        int l = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0) z++;
            while( z>k)
            {
                z-=nums[l] == 0 ;
                l++;
            }
            ans = max(ans,i-l +1);
        }
        return ans;
    }
};