class Solution {
    typedef pair<int,int> p;
    vector<int>dx{0,-1,1,0};
    vector<int>dy{1,0,0,-1};
    vector<vector<int>>vis;
    queue<p>q;
    int n,m;
private:
    bool issafe(int i,int j)
    {
        return (i >=0 && j >=0 && i<n && j<m && vis[i][j] == 0);
    }
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        vis[i][j] = 1;
        for(int d=0;d<4;d++)
        {
            int nx = dx[d] + i;
            int ny = dy[d] + j;
            if(issafe(nx,ny) && grid[nx][ny] == 1)
            {   
                q.push({nx,ny});
                dfs(nx,ny,grid);
            }   
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            bool f = false;
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    dfs(i,j,grid);
                    f = true;
                    break;
                }
            }
            if(f) break;
        }

        int ans = 0;
        while(!q.empty())
        {
            int si = q.size();
            for(int i=0;i<si;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                cout<<x<<" "<<y<<endl;
                for(int d=0;d<4;d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(issafe(nx,ny))
                    {
                        if(grid[nx][ny] == 1) return ans;
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};