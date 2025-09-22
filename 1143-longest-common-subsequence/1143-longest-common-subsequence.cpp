class Solution {
private:
    int rec(int i,int j,string s,string t)
    {
        if(i == s.size() || j == t.size()) return 0;
        int ta = 0;
        if(s[i] == t[j])
        {
            ta = 1 + rec(i+1,j+1,s,t);
        }
        int nt1 = rec(i+1,j,s,t);
        int nt2 = rec(i,j+1,s,t);
        return max({ta,nt1,nt2});
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[n][m] = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int ta = 0;
                if(text1[i] == text2[j])
                {
                    ta = 1 + dp[i+1][j+1];
                }
                int nt1 = dp[i+1][j];
                int nt2 = dp[i][j+1];
                dp[i][j] = max({ta,nt1,nt2});
            }
        }
        return dp[0][0];
    }
};