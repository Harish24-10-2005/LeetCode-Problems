class Solution {
private:
    vector<vector<int>>adj;
    vector<int>res;
    vector<int>vis;
    int n;
    int maxx = INT_MIN;
    void dfs(int node,int temp)
    {
        res[node] = temp;
        vis[node] = 1;
        for(auto a:adj[node])
        {
            if(vis[a] == 0)
            {
                dfs(a,temp + 1);
            }
            else if(vis[a] == 1)
            {
                maxx = max(maxx,temp - res[a]+ 1);
            }
        }
        vis[node] = 2;
    }

public:
    int longestCycle(vector<int>& edges) {
        n = edges.size();
        adj.resize(n);
        res.assign(n, 0);
        vis.assign(n, 0);

        for(int i=0;i<n;i++)
        {
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0) dfs(i,0);
        }
        return maxx == INT_MIN ? -1 : maxx;
    }
};