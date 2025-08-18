class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        long long MOD = 1e9 + 7;
        for(int i=0;i<queries.size();i++)
        {
            int idx = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            while(idx <= r)
            {
                nums[idx] = ((nums[idx]% MOD)*v) % MOD;
                idx+=k;
            }
        }
        for(int i:nums)
        {
            ans^=i;
        }
        return ans;
    }
};