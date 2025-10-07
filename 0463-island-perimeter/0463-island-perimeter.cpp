class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        vector<int>dx{-1,1,0,0};
        vector<int>dy{0,0,1,-1};

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    ans+=4;
                    if(i > 0 && grid[i-1][j] == 1) ans-=2;
                    if(j > 0 && grid[i][j-1] == 1) ans-=2;
                }
            }
        }
        return ans;
    }
};