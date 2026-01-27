class Solution {
private:
    vector<vector<pair<int,int>>>adj;
    void dijis(int node,vector<int>&dist){
        dist[node] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,node});
        while(!pq.empty()){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            for(auto e:adj[u]){
                int v = e.first;
                int c = e.second;
                if(w + c < dist[v]){
                    dist[v] = w + c;
                    pq.push({c + w,v});
                }
            }
        }
    }
public:
    int minCost(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist1(n,INT_MAX),dist2(n,INT_MAX);
        dijis(0,dist1);
        adj.clear();
        adj.resize(n);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[v].push_back({u,w});
        }
        dijis(n-1,dist2);
        for(auto i:dist1) cout<<i<<" ";
        cout<<endl;
        for(auto i:dist2) cout<<i<<" ";

        int ans = dist1[n-1];
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist1[v] == INT_MAX || dist2[u] == INT_MAX) continue;
            ans = min(ans,dist1[v] + dist2[u] + 2 * w);
        }
        return ans;
    }
};