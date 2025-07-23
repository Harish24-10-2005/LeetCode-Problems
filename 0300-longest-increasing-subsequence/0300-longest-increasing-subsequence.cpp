class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int>a;
        a.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>a.back())
            {
                a.push_back(nums[i]);
                ans++;
            }else if(nums[i]<a.back())
            {
                auto l = lower_bound(a.begin(),a.end(),nums[i]);
                int idx = l - a.begin();
                a[idx] = nums[i];  
            }
        }
        return ans;
    }
};