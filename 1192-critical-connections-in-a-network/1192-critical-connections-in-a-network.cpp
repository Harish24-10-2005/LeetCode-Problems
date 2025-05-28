class Solution {
    private:
    int t = 1;
    void dfs(int node,int p,vector<int>&tin,vector<int>&low,vector<int>&vis,vector<vector<int>>&adj,vector<vector<int>>&res)
    {
        vis[node] = 1;
        tin[node] = low[node] = t++;
        for(int i:adj[node])
        {
            if(i == p) continue;
            if(vis[i] != 1)
            {
                dfs(i,node,tin,low,vis,adj,res);
                low[node] = min(low[node],low[i]);
                if(low[i] > tin[node])
                {
                    res.push_back({node,i});
                }
            }
            else
            {
                low[node] = min(low[node],low[i]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto a:connections)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int>tin(n);
        vector<int>low(n);
        vector<vector<int>>res;
        vector<int>vis(n,0);
        dfs(0,-1,tin,low,vis,adj,res);
        return res;
    }
};