class Solution {
private:
    int n;
    vector<vector<int>>adj;
    int bfs(int node){
        vector<int>vis(n,-1); 
        queue<vector<int>>q;
        q.push({node,0,-1});
        while(!q.empty()){
            int u = q.front()[0];
            int l = q.front()[1];
            int par = q.front()[2];
            q.pop();
            vis[u] = l;
            for(int v:adj[u]){
                if(v == par) continue;
                if(vis[v]== -1){
                    q.push({v,l+1,u});
                }
                else{
                    return vis[v] + l + 1;
                }   
            }
        }
        return INT_MAX;
    }
public:
    int findShortestCycle(int num, vector<vector<int>>& edges) {
        n = num;
        adj.resize(n);
        int ans = INT_MAX;
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            ans = min(ans,bfs(i));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};