class Solution {
public:
    int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        vector<long long >dist(n,LLONG_MAX);
        vector<long long >way(n,0);
        for(auto a:roads)
        {
            int u = a[0];
            int v = a[1];
            int c = a[2];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        priority_queue<pair<long long ,int>,vector<pair<long long ,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0] = 0;
        way[0] = 1;
        // int minn = INT_MAX;
        long long  ans = 0;
        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            int u = a.second;
            long long  t = a.first;
            for(auto n:adj[u])
            {
                long long  newt = t+n.second;
                int v = n.first;
                if(newt < dist[v])
                {
                    dist[v] = newt;
                    way[v] = way[u];
                    pq.push({newt,v});
                } 
                else if(newt == dist[v])
                {
                    way[v] = (way[v] + way[u]) % MOD;
                }
            }
            // cout<<endl;
        }
        return way[n-1];
    }
};