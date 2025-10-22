class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        typedef pair<int,int> pp;
        vector<vector<pp>>adj(n+1);
        for(auto a:times)
        {
            int u = a[0];
            int v = a[1];
            int w = a[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        priority_queue<pp,vector<pp>,greater<>>pq;
        pq.push({0,k});
        int ans = 0;
        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();

            int w = a.first;
            int node = a.second;
            for(auto c:adj[node])
            {
                int cnode = c.first;
                int cw = c.second;
                if(dist[cnode] > cw + w)
                {
                    dist[cnode] = cw + w;
                    pq.push({cw+w,cnode});
                }
            }
        }
        for(int i = 1;i<=n;i++)
        {
            cout<<dist[i]<<" ";
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};