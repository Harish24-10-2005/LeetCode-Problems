class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i =0;i<flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int p = flights[i][2];
            adj[u].push_back({v,p});
        }
        typedef pair<int,pair<int,int>> ppi;
        queue<ppi>pq;

        vector<int>dist(n,INT_MAX);
        pq.push({0,{0,src}});
        dist[src] = 0;

        while(!pq.empty())
        {
            auto a = pq.front();
            pq.pop();

            int p = a.first;
            int s = a.second.first;
            int cur = a.second.second;

            if(s > k) continue;
            for(auto b:adj[cur])
            {
                int node = b.first;
                int np = b.second;
                if(s <= k && dist[node] > p + np)
                {
                    dist[node] = p+np;
                    pq.push({p+np,{s+1,node}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];

    }
};