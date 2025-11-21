class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n+1,vector<int>(n+1,0));

        for(auto a:queries)
        {
            int x1 = a[0];
            int y1 = a[1];
            int x2 = a[2];
            int y2 = a[3];
            mat[x1][y1]++;
            mat[x1][y2+1]--;
            
            mat[x2+1][y1]--;
            mat[x2+1][y2+1]++;
        }

        for(int i=0;i<=n;i++)
        {
            int t = 0;
            for(int j=1;j<=n;j++)
            {
                mat[i][j] = mat[i][j-1] + mat[i][j];
                // cout<<mat[i][j];
            }
            mat[i].pop_back();
            // cout<<endl;
        }


        for(int i=0;i<n;i++)
        {
            // int t = 0;
            for(int j=1;j<n;j++)
            {
                mat[j][i] = mat[j-1][i] + mat[j][i];
            }
            // mat[i].pop_back();
        }
        if(!mat.empty())mat.pop_back();
        
        return mat;
    }
};