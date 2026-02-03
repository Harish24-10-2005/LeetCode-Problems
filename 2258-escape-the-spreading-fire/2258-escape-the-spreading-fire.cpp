class Solution {
    vector<int>dx{1,-1,0,0};
    vector<int>dy{0,0,-1,1};
    vector<vector<int>>vis;
    int n,m;
private:
    int dfs(int i,int j,int minn,int idx,int numidx,vector<vector<int>>&grid){
        if(i == n-1 && j == m-1){
            return (minn - numidx);
        }
        if(i >= n || j >= m) return INT_MIN;

        if(grid[i][j] <= idx) return INT_MIN;
        int ans = INT_MIN;
        for(int d = 0;d<4;d++){
            int nx = i + dx[d];
            int ny = j + dy[d];
            if(nx < n && nx >= 0 && ny < m && ny >=0 && grid[nx][ny] != -1 && vis[nx][ny] == 0){
                vis[nx][ny] = 1;
                int temp = minn;
                int temp_idx = numidx;
                if(temp > grid[nx][ny]){
                    temp = grid[nx][ny];
                    temp_idx = idx + 1;
                }
                ans = max(ans,dfs(nx,ny,temp,idx + 1,temp_idx,grid));
                vis[nx][ny] = 0;
            }
        }
        return ans;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) grid[i][j] = -1;
                else if(grid[i][j] == 1){
                    pq.push({1,{i,j}});
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
        vis[0][0] = 1;
        int ans = dfs(0,0,grid[0][0],1,1,grid);
        cout<<ans<<endl;
        // cout<<INT_MAX;
        if(ans == 0) return 0;
        if(ans == INT_MIN) return -1;
        return ans == INT_MAX-1 ? 1e9 : ans-1;
    }
};