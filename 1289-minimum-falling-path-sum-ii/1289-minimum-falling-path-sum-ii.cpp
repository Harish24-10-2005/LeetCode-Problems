class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

        for(int j=0;j<n;j++) dp[0][j] = grid[0][j];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j-1>=0) dp[i][j] = min(dp[i][j],dp[i-1][j-1]+grid[i][j]);
                if(j+1 <n) dp[i][j] = min(dp[i][j],dp[i-1][j+1]+grid[i][j]);
                // if()dp[i][j] = min(dp[i][j],dp[i-1][j]+grid[i][j]);
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};