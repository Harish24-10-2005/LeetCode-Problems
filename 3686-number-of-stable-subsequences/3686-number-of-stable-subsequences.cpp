class Solution {
private:
    long long MOD = 1e9 + 7;
    vector<long long>pow;
    int rec(int i,int p,int num,vector<int>&nums,vector<vector<vector<int>>>&dp)
    {
        if(num >= 3)
        {
            return pow[nums.size()-i];
        }
        if(i == nums.size())
        {
            return 0;
        }

        int p_new = p == -1 ? 2 : p;
        if(dp[i][num][p_new] != -1) return dp[i][num][p_new]; 

        int temp = (p == -1 || nums[i]%2 == p)? num+1 : 1;
        int take = rec(i+1,nums[i]%2,temp,nums,dp) % MOD;
        int nt = rec(i+1,p,num,nums,dp) % MOD;

        return dp[i][num][p_new] =  (take + nt) % MOD;
    }
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(4,vector<int>(3,-1)));
        pow.resize(n+1);
        pow[0] = 1;
        for(int i=1;i<=n;i++) pow[i] = (pow[i-1] * 2LL) % MOD;

        int nt = rec(0,-1,0,nums,dp)%MOD;
        long long can = (pow[n] - 1 + MOD)%MOD;
        return (can - nt + MOD)%MOD;
    }
};