class Solution {
private:
    vector<vector<int>>adj;
    vector<int>vis,path,dep;
    int maxx = -1;
    void dfs(int node,int dist){
        path[node] = 1;
        vis[node] = 1;
        dep[node] = dist;
        for(int i:adj[node]){
            if(!vis[i]){
                dfs(i,dist+1);
            }
            else if(path[i]){
                maxx = max(maxx,dist - dep[i]  + 1);
            }
        }
        path[node] = 0;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        adj.resize(n);
        vis.assign(n,0);
        path.assign(n,0);
        dep.assign(n,0);
        for(int i = 0;i<n;i++){
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,0);
            }
        }
        return maxx;
    }
};