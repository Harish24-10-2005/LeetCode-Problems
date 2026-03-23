class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 1e9 + 7;
        vector<vector<pair<long long,long long>>>dp(n,vector<pair<long long,long long>>(m));
        dp[0][0] = {grid[0][0],grid[0][0]};
        for(int i=1;i<n;i++){
            dp[i][0] = {dp[i-1][0].first * grid[i][0],dp[i-1][0].first * grid[i][0]};
        }
        for(int i=1;i<m;i++){
            dp[0][i] = {dp[0][i-1].first * grid[0][i],dp[0][i-1].first * grid[0][i]};
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j].first =  max({
                    dp[i-1][j].first * grid[i][j],
                    dp[i-1][j].second * grid[i][j],
                    dp[i][j-1].first * grid[i][j],
                    dp[i][j-1].second * grid[i][j]
                });
                dp[i][j].second =  min({
                    dp[i-1][j].first * grid[i][j],
                    dp[i-1][j].second * grid[i][j],
                    dp[i][j-1].first * grid[i][j],
                    dp[i][j-1].second * grid[i][j]
                });
                
            }
        }
        long long ans = dp[n-1][m-1].first;

        return ans < 0 ? -1 : ans % MOD;
    }
};