class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp = triangle;

        for(int i=1;i<n;i++)
        {
            int m = triangle[i].size();
            for(int j=0;j<m;j++)
            {
                int f = INT_MAX;
                if(j-1 >= 0)
                {
                    f = dp[i-1][j-1];
                }
                int s = INT_MAX;
                if(j < m-1)
                {
                    s = dp[i-1][j];
                }
                dp[i][j] = min(f,s) + dp[i][j];
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};