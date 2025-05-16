class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>g(n,vector<int>(n,INT_MAX));
        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            g[u][v] = wt;
            g[v][u] = wt;
        }
        for(int i=0;i<n;i++) g[i][i] = 0;

        for(int v =0;v<n;v++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(g[i][v]!=INT_MAX && g[v][j]!= INT_MAX)
                    g[i][j] = min(g[i][j],g[i][v]+g[v][j]);
                }
            }
        }
        int res = -1;
        int minr = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int r=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && g[i][j] <=distanceThreshold) r++;
            }
            if(r<=minr)
            {
                minr = r;
                res = i;
            }
        }
        return res;
    }
};