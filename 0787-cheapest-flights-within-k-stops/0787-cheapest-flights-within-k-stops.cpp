class Solution {
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k) {
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][k + 1] = 0;  

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {src, k + 1}});

        while (!pq.empty()) {
            auto [cost, sc] = pq.top();
            auto [node, stopsLeft] = sc;
            pq.pop();

            if (cost > dist[node][stopsLeft]) 
                continue;

            if (node == dst) 
                return cost;

            if (stopsLeft == 0) 
                continue;
            for (auto &edge : adj[node]) {
                int nxt     = edge.first;
                int price   = edge.second;
                int newCost = cost + price;
                if (newCost < dist[nxt][stopsLeft - 1]) {
                    dist[nxt][stopsLeft - 1] = newCost;
                    pq.push({newCost, {nxt, stopsLeft - 1}});
                }
            }
        }

        return -1; 
    }
};