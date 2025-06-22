class Solution {
private :
    int rec(int n,vector<int>&dp)
    {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n]!=-1) return dp[n];

        int one = rec(n-1,dp);
        int two = rec(n-2,dp);

        dp[n] = one + two;
        return dp[n];
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return rec(n,dp);
    }
};