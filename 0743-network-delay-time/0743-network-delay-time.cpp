class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:times)
        {
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty())
        {
            auto a = pq.top();
            pq.pop();

            int node = a.second;
            int wt = a.first;
            for(auto i:adj[node])
            {
                if(wt + i.second < dist[i.first])
                {
                    dist[i.first] = wt + i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
        int res = INT_MIN;
        for(int i=1;i<dist.size();i++)
        {
            cout<<dist[i]<<endl;
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
            res = max(dist[i],res);
        }
        return res;
    }
};