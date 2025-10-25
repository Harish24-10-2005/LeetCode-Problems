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
        priority_queue<ppi,vector<ppi>,greater<>>pq;
        
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        pq.push({0,{0,src}});
        dist[src][0] = 0;

        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();

            int p = a.first;
            int s = a.second.first;
            int cur = a.second.second;
            if(cur == dst)
            {
                return p;
            }
            for(auto b:adj[cur])
            {
                int node = b.first;
                int np = b.second;
                if(s <= k && dist[node][s + 1] > p + np)
                {
                    dist[node][s+1] = p+np;
                    pq.push({p+np,{s+1,node}});
                }
            }
        }
        return -1;

    }
};