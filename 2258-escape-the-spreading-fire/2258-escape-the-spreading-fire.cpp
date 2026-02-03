class Solution {
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,-1,1};
    int n,m;
private:
    int bfs(int k,vector<vector<int>>&grid){
        if(k >= grid[0][0]) return false;
        vector<vector<int>>vis;
        vis.assign(n,vector<int>(m,-1));
        vis[0][0] = k;
        queue<vector<int>>q;
        q.push({0,0});
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int t= vis[x][y];
            q.pop();
            for(int d = 0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < n && nx >= 0 && ny < m && ny >=0 && grid[nx][ny] != -1 && vis[nx][ny] == -1){
                    if(nx == n-1 && ny == m-1){
                        if(t+1 <= grid[nx][ny]) return true;
                    }
                    else if(t+1 < grid[nx][ny]){
                        vis[nx][ny] = t + 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) grid[i][j] = -1;
                else if(grid[i][j] == 1){
                    pq.push({0,{i,j}});
                }
                else{
                    grid[i][j] = INT_MAX;
                }
            }
        }

        while(!pq.empty()){
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int d=0;d<4;d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < n && nx >= 0 && ny < m && ny >=0 && grid[nx][ny] != -1 && (grid[nx][ny] > (t + 1))){
                    grid[nx][ny] = t + 1;
                    pq.push({t + 1,{nx,ny}});
                }
            }
        }
        int l = 0;
        int r = 1e9;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(bfs(mid,grid)){
                ans = mid;
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        return ans;
    }
};