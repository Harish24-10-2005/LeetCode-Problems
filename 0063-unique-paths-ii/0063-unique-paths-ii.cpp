class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size();
        int m = o[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(o[i][0] == 1)
            {
                break;
            }
            else dp[i][0] = 1;
        }
        for(int i=0;i<m;i++)
        {
            if(o[0][i] == 1)
            {
                break;
            }
            else dp[0][i] = 1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(o[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};