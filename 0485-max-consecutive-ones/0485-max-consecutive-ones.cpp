class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int t = 0;
        for(auto a:nums)
        {
            if(a == 0)
            {
                t = 0;
            }
            else t++;
            ans = max(ans,t);
        }
        return ans;
    }
};