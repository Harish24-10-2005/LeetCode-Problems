class Solution {
    // int rec(int i,int j,string w1,string w2,vector<vector<int>>&dp)
    // {
    //     if(j == w2.size()) return w1.size() - i;
    //     if(i ==  w1.size()) return w2.size() - j;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(w1[i] == w2[j]) 
    //     {
    //         return dp[i][j] = rec(i+1,j+1,w1,w2,dp);
    //     }
    //     int r = 1 + rec(i+1,j+1,w1,w2,dp);
    //     int d = 1 + rec(i+1,j,w1,w2,dp);
    //     int in = 1 + rec(i,j+1,w1,w2,dp);
    //     return dp[i][j] = min({r,d,in});
    // }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++)
        {
            dp[i][m] = n-i;
        }
        for(int i=0;i<m;i++)
        {
            dp[n][i] = m-i;
        }

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(word1[i] == word2[j]) 
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    int r = 1 + dp[i+1][j+1];
                    int d = 1 + dp[i+1][j];
                    int in = 1 + dp[i][j+1];
                    dp[i][j] = min({r,d,in});
                }
            }
        }
        return dp[0][0];
    }
};