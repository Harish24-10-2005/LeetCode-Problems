class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        vector<int>ways(n,0);
        vector<long long> dist(n, LLONG_MAX);
        vector<vector<pair<int,int>>>adj(n);

        for(auto a:roads)
        {
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        pq.push({0,0});
        dist[0]= 0;
        ways[0] = 1;

        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            int node = a.second;
            long long cost = a.first;
            if (cost > dist[node]) continue;
            for(auto a:adj[node])
            {
                long long tempc = cost + a.second;
                if(tempc == dist[a.first])
                {
                    ways[a.first]=(ways[a.first] + ways[node])% MOD;
                }
                else
                {
                    if(tempc < dist[a.first])
                    {
                        dist[a.first] = tempc;
                        ways[a.first] = ways[node];
                        pq.push({tempc,a.first});
                    }
                }
            }
        }
        return ways[n-1] % MOD;
    }
};