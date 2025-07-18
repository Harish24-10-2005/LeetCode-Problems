class Solution {
private: 
    bool rec(int i,int j,string s,string p,vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0) 
        {
            for(int k=j;k>=0;k--) if(p[k] != '*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j] == 1;
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = rec(i-1,j-1,s,p,dp);
        if(p[j] == '*') return dp[i][j] = (rec(i-1,j,s,p,dp) || rec(i,j-1,s,p,dp));
        return dp[i][j] = 0;
    } 
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        dp[0][0] = 1;
        for(int i=1;i<=n;i++) dp[i][0] = 0;

        for(int j=1;j<=m;j++)
        {
            bool f = true;
            for(int k=0;k<j;k++)
            {
                if(p[k] != '*')
                {
                    f= false;
                    break;
                } 
            }
            dp[0][j] = f;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                else dp[i][j] = 0;
            }
        }
        return dp[n][m];
    }
};