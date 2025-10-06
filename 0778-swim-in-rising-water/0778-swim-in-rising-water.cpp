class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        int ans = 0;
        vector<int>dx{0,-1,1,0};
        vector<int>dy{1,0,0,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({grid[0][0],{0,0}});
        vis[0][0] = 1;
        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            int h = a.first;
            int x = a.second.first;
            int y = a.second.second;
            cout<<"x "<<x<<" y "<<y<<" h "<<h<<endl;
            if(x == n-1 && y == n-1)
            {
                ans = h;
                break;   
            }
            for(int d = 0;d<4;d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && ny >=0 && nx < n && ny < n && vis[nx][ny] == 0)
                {
                    vis[nx][ny] = 1;
                    if(h >= grid[nx][ny])
                    {
                        pq.push({h,{nx,ny}});
                    }
                    else
                    {
                        pq.push({grid[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return ans;

    }
};