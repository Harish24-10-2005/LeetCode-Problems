class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        int far = 0;
        int cur = 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            far = max(far,i+nums[i]);
            if(i == cur)
            {
                cnt++;
                cur = far;
            }
        }
        return cnt;
    }
};