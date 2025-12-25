class Solution {
private:    
    vector<int>topo;
    vector<vector<int>>adj;
    vector<int>vis;
    bool dfs(int node){
        vis[node] = 1;
        for(int i:adj[node]){
            if(vis[i] == 1) return true;
            if(vis[i] == 2) continue;
            if(dfs(i)) return true;
        }
        vis[node] = 2;
        topo.push_back(node);
        return false;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vis.assign(n,0);
        adj.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
        }
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                if(dfs(i)) return -1;
            }
        }
        vector<vector<int>>dp(n,vector<int>(26,0));
        reverse(topo.begin(),topo.end());
        int ans = 0;
        for(int u:topo){
            int ch = colors[u] - 'a';
            dp[u][ch]++;
            ans = max(ans,dp[u][ch]);
            for(int v:adj[u]){
                for(int j=0;j<26;j++){
                    dp[v][j] = max(dp[v][j],dp[u][j]);
                    ans = max(ans,dp[v][j]);
                }
            }
        }
        return ans;
    }
};