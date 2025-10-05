class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            vector<int> maxj;
            int maxx = INT_MIN;
            for(int j=0;j<m;j++)
            {
                if(heights[i][j] > maxx)
                {
                    maxx = heights[i][j];
                    maxj = {j};
                }
                if(heights[i][j] == maxx)
                {
                    maxj.push_back(j);
                }
            }
            for(int k = 0;k<maxj.size();k++)
            {
                st.insert({i,maxj[k]});
            }
        }
        for(int j=0;j<m;j++)
        {
            vector<int>maxi;
            int maxx = INT_MIN;
            for(int i=0;i<n;i++)
            {
                if(heights[i][j] > maxx)
                {
                    maxx = heights[i][j];
                    maxi = {i};
                }
                else if(heights[i][j] == maxx)
                {
                    maxi.push_back(i);
                }
            }
            for(int k = 0;k<maxi.size();k++)
            {
                st.insert({maxi[k],j});
            }
        }
        st.insert({0,m-1});
        st.insert({n-1,0});
        vector<vector<int>>res;
        vector<vector<int>>vis;
        vector<int>dx{-1,0,1,0};
        vector<int>dy{0,1,0,-1};
        for(auto a:st)
        {
            bool p = false;
            bool at = false;
            vis.assign(n,vector<int>(m,0));
            queue<vector<int>>q;
            int i = a[0];
            int j = a[1];
            q.push({heights[i][j],i,j});
            vis[i][j] = 1;
            while(!q.empty())
            {
                auto b = q.front();
                q.pop();
                int h = b[0];
                int x = b[1];
                int y = b[2];
                if(x == 0 || y == 0) p = true;
                if(x == n-1 || y == m-1) at = true;
                if(p && at) break;
                for(int d = 0;d<4;d++)
                {
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    if(nx < n && ny < m && nx >=0 && ny >=0 && vis[nx][ny] == 0 && heights[nx][ny] <= heights[x][y])
                    {
                        vis[nx][ny] = 1;
                        q.push({heights[nx][ny],nx,ny});
                    }
                } 
            }
            if(p && at) res.push_back(a);
        }
        return res;
    }
};