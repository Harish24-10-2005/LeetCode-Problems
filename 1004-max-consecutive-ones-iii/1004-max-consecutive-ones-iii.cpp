class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros =0;
        int res =0;
        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0) zeros++;
            while(zeros>k)
            {
                if(nums[l] == 0) zeros--;
                l++;
            }
            res = max(res,i-l+1);
        }
        return res;
    }
};