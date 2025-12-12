class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>dir = mat;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                    dir[i][j] = 0;
                }
            }
        }
        vector<int>dx{0,1,0,-1};
        vector<int>dy{1,0,-1,0};
        while(!q.empty())
        {
            int x= q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny >=0 && nx<mat.size() && ny<mat[0].size() && vis[nx][ny]!=1)
                { 
                    vis[nx][ny] = 1;
                    dir[nx][ny] = t+1;
                    q.push({{nx,ny},t+1});
                }
            }
        }
        return dir;
    }
};