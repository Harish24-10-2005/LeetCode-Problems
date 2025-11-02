class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = 0;
        vector<vector<int>>vis(m,vector<int>(n,-1));
        for(auto a:walls)
        {
            vis[a[0]][a[1]] = 1;
        }
        for(auto a:guards)
        {
            int x = a[0];
            int y = a[1];
            vis[x][y] = 2;
        }
        for(int i=0;i<m;i++)
        {
            bool v = false;
            for(int j=0;j<n;j++)
            {
                if(vis[i][j] == 1) v = false;
                else if(vis[i][j] == 2) v = true;
                else if(v) vis[i][j] = 3;
            }
            v = false;
            for(int j=n-1;j>=0;j--)
            {
                if(vis[i][j] == 1) v = false;
                else if(vis[i][j] == 2) v = true;
                else if(v) vis[i][j] = 3;
            }
        }
        for(int j=0;j<n;j++)
        {
            bool v = false;
            for(int i=0;i<m;i++)
            {
                if(vis[i][j] == 1) v = false;
                else if(vis[i][j] == 2) v = true;
                else if(v) vis[i][j] = 3;
            }
            v = false;
            for(int i=m-1;i>=0;i--)
            {
                if(vis[i][j] == 1) v = false;
                else if(vis[i][j] == 2) v = true;
                else if(v) vis[i][j] = 3;
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(vis[i][j] == -1) ans++;
            }
        }
        return ans;
    }
};