class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int e = 0;
        int o = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2 ==0) e+=nums[i];
            else o+=nums[i];
        }
        return e-o;
    }
};