class Solution {
private:
    vector<vector<pair<int,int>>>adj;
    int dijis(int node,int n,vector<int>&dist){
        // dist[node] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,node});
        while(!pq.empty()){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if(dist[u] != -1) continue;
            dist[u] = w;
            if(u == n-1) return w;
            for(auto e:adj[u]){
                int v = e.first;
                int c = e.second;
                if(dist[v] == -1){
                    pq.push({c + w,v});
                }
            }
        }
        return dist[n-1];
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2 * w});
        }
        vector<int>dist1(n,-1);
        return dijis(0,n,dist1);
    }
};