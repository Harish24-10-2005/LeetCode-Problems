class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int res =0;
        priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        pq.push({grid[0][0], {0, 0}});

        vector<int>dx{1,0,-1,0};
        vector<int>dy{0,1,0,-1};

        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();

            int x = a.second.first;
            int y = a.second.second;
            int ht = a.first;
            if(x == n-1 && y == n-1){
                 res = ht;
                 break;
            }
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx >=0 && ny >=0 && nx<n && ny<n && vis[nx][ny] !=1)
                {
                    vis[nx][ny] = 1;
                    pq.push({max(ht, grid[nx][ny]), {nx, ny}});
                }
            }
        }
        return res;
    }
};