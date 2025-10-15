class Solution {
    void row(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&h)
    {
        for(int i=0;i<n;i++)
        {
            vector<int>pre(m);
            pre[0] = h[i][0];
            for(int j=1;j<m;j++)
            {
                pre[j] = max(pre[j-1],h[i][j]);
            }
            dp[i][m-1] = h[i][m-1]; 
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j] = max(dp[i][j+1],h[i][j]);
            }
            for(int j=0;j<m;j++)
            {
                dp[i][j] = min(dp[i][j],pre[j]);
            }
        }
    }
    void col(int n,int m,vector<vector<int>>&dp,vector<vector<int>>&h)
    {
        for(int i=0;i<m;i++)
        {
            vector<int>pre(n),suf(n);
            pre[0] = h[0][i];
            for(int j=1;j<n;j++)
            {
                pre[j] = max(pre[j-1],h[j][i]);
            }
            suf[n-1] = h[n-1][i]; 
            for(int j=n-2;j>=0;j--)
            {
                suf[j] = max(suf[j+1],h[j][i]);
            }
            for(int j=0;j<n;j++)
            {
                dp[j][i] = min({dp[j][i],pre[j],suf[j]});
            }
        }
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        row(n,m,dp,heightMap);
        col(n,m,dp,heightMap);
        int ans = 0;
        for(int i=0;i<n;i++) dp[i][0] = heightMap[i][0];
        for(int j=0;j<m;j++) dp[0][j] = heightMap[0][j];
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                int water = max(0, dp[i][j] - heightMap[i][j]);
                ans += water;
            }
        }
        return ans;
    }
};