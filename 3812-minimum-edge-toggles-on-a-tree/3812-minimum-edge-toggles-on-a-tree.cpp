class Solution {
private:
    vector<vector<pair<int,int>>>adj;
    vector<int>diff;
    void dfs(int node,int par,vector<int>&res){
        for(auto a:adj[node]){
            int idx = a.second;
            int u = a.first;
            if(u == par) continue;
            dfs(u,node,res);
            if(diff[u]){
                res.push_back(idx);
                diff[node] = 1-diff[node];
            }
        }
    }
    
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<int>res;
        adj.resize(n);
        diff.assign(n,0);
        int i=0;
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
            i++;
        }
        for(int i=0;i<n;i++){
            diff[i] = (start[i] != target[i]);
        }
        dfs(0,-1,res);
        sort(res.begin(),res.end());
        if(diff[0] != 1) return res;
        
        return {-1}; 
    }
};