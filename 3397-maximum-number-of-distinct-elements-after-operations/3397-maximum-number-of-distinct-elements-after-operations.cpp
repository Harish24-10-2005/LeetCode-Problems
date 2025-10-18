class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int last = INT_MIN;
        for(auto a:nums)
        {
            int l = a - k;
            int r = a + k;
            int c = max(l,last+1);
            if(c <= r)
            {
                ans++;
                last = c;
            }
        }
        return ans;
    }
};