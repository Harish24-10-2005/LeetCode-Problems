class DisjointSet {
    vector<int>parent;
public:
    vector<int>size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;

        vector<int>dx{1,0,-1,0};
        vector<int>dy{0,1,0,-1};

        DisjointSet d(n*n);
        vector<pair<int,int>>z;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    int node = i*n+j;
                    int p = d.findUPar(node);
                    set<int>st;
                    for(int k=0;k<4;k++)
                    {
                        int nx = i+dx[k];
                        int ny = j+dy[k];

                        if(nx>=0 && ny>=0 && nx < n && ny <n && grid[nx][ny] == 1)
                        {
                            int newnode = nx*n+ny;
                            int np = d.findUPar(newnode);
                            d.unionBySize(p,np);
                        }
                    }
                }
                else z.push_back({i,j});
            }
        }
        for(auto a:z)
        {
            int x = a.first;
            int y = a.second;
            set<int>st;
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx>=0 && ny>=0 && nx < n && ny <n && grid[nx][ny] == 1)
                {
                    int p = d.findUPar(nx*n+ny);
                    st.insert(p);
                }
            }
            int total = 1;
            for(int i:st)
            {
                total+=d.size[i];
            }
            res = max(res,total);
        }
        return z.size() == 0?n*n:res;
    }
};