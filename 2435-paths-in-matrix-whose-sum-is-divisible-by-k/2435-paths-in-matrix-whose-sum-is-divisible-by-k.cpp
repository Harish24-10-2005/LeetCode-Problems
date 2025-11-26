class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,0)));

        dp[0][0][grid[0][0] % k] = 1;
        int pre = grid[0][0] % k;

        for(int i=1;i<n;i++)
        {
            int rem =  (pre + (grid[i][0] % k)) % k;
            dp[i][0][rem] += 1;
            pre = rem;
        }

        pre = grid[0][0] % k;
        for(int j=1;j<m;j++)
        {
            int rem =  (pre + (grid[0][j] % k)) % k;
            dp[0][j][rem] += 1;
            pre = rem;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int rem = grid[i][j] % k;
                for(int l =0;l<=k;l++)
                {
                    int up = dp[i-1][j][l];
                    if(up != 0)
                    {
                        dp[i][j][(l + rem) % k] =  up; 
                    }
                    int left = dp[i][j-1][l];
                    if(left != 0)
                    {
                        dp[i][j][(l + rem) % k] += left; 
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};