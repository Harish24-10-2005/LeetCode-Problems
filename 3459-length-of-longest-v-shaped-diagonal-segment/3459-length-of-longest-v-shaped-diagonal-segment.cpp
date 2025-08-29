class Solution {
private:
    bool issafe(int x,int y,int n,int m)
    {
        return (x<n && y<m && x>=0 && y>=0);
    }
    int rec(int i,int j,int d,bool turn,int n,int m,int pre,vector<vector<int>>&grid,vector<int>&dx,vector<int>&dy,vector<int>&dir,vector<vector<vector<vector<int>>>>&dp)
    {
        if(!issafe(i,j,n,m) || grid[i][j] == pre || grid[i][j] == 1) return 0;
        // cout<<"i = "<<i<<" j= "<<j<<endl;
        if(dp[i][j][d][turn] != -1) return dp[i][j][d][turn];
        int t = INT_MIN;
        if(turn)
        {
            t = 1+ rec(i+dx[dir[d]],j+dy[dir[d]],dir[d],false,n,m,grid[i][j],grid,dx,dy,dir,dp);
        }
        int nt = 1 + rec(i+dx[d],j+dy[d],d,turn,n,m,grid[i][j],grid,dx,dy,dir,dp);
        return dp[i][j][d][turn] = max(t,nt);
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dx{-1,-1,1,1};
        vector<int>dy{-1,1,1,-1};
        vector<int>dir{1,2,3,0};
        int ans = 0;
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(4,vector<int>(2,-1))));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans,1);
                    for(int d=0;d<4;d++)
                    {
                        int nx = i+dx[d];
                        int ny = j+dy[d];
                        if(issafe(nx,ny,n,m) && grid[nx][ny] == 2)
                        {
                            ans = max(ans,1 + rec(nx,ny,d,true,n,m,-1,grid,dx,dy,dir,dp));
                        }
                        cout<<"==========================="<<endl;
                    }
                }
            }
        }
        return ans;
    }
};