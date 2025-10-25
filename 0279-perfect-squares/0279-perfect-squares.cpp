class Solution {
    vector<int>dp;
private:
    int rec(int n)
    {
        if(n == 0) return 0;
        int ans = INT_MAX;
        if(dp[n] != -1) return dp[n];
        for(int i=1;i*i<=n;i++)
        {
            ans = min(ans,1 + rec(n - i*i));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        dp.assign(n+1,-1);
        return rec(n);
    }
};