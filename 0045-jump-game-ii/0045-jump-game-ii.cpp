class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        int maxd = 0;
        int c = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxd = max(maxd,i+nums[i]);
            if(i == c)
            {
                cnt++;
                c = maxd;
            }
        }
        return cnt;
    }
};