class Solution {
private:
    int rec(int i,int j,string s,string t,vector<vector<int>>&dp)
    {
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ta = INT_MIN;
        if(s[i] == t[j])
        {
            dp[i][j] = rec(i-1,j,s,t,dp)+rec(i-1,j-1,s,t,dp);
        }
        else dp[i][j] = rec(i-1,j,s,t,dp);
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};