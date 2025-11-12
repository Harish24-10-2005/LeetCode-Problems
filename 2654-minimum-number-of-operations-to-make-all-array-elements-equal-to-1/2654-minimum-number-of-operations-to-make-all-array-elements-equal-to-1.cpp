class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int cnt = 0;
        for(auto a:nums)
        {
            if(a == 1) cnt++;
        }
        if(cnt > 0) return n - cnt;
        for(int i=0;i<n;i++)
        {
            int g = nums[i];
            for(int j=i+1;j<n;j++)
            {
                g = __gcd(g,nums[j]);
                if(g == 1)
                {
                    ans = min(ans,j-i);
                    break;
                }   
            }
        }
        return ans == INT_MAX ? -1 : ans + n - 1;
    }
};