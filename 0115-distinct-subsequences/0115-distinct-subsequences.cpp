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
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // for(int i=0;i<m;i++) dp[i][0] = 1;

        return rec(n-1,m-1,s,t,dp);
    }
};