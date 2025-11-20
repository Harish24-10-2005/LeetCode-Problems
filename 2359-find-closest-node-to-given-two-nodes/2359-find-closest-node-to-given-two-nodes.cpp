class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        vector<int>val(n,INT_MAX);
        queue<int>q;
        vector<int>vis(n,-1);
        q.push(node1);
        val[node1] = 0;
        vis[node1] = 1;
        int d = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto a:adj[node])
            {
                if(vis[a] == -1) 
                {
                    vis[a] = 1;
                    val[a] = d + 1;
                    q.push(a);
                }
            }
            d++;
        }
        vis.assign(n,-1);
        vector<int>val2(n,INT_MAX);
        q.push(node2);
        vis[node2] = 1;
        val2[node2] = 0;
        d = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto a:adj[node])
            {
                if(vis[a] == -1) 
                {
                    vis[a] = 1;
                    val2[a] = d + 1;
                    q.push(a);
                }
            }
            d++;
        }
        int ans = INT_MAX;
        int res = -1;
        for(int i=0;i<n;i++)
        {
            // cout<<val[i] <<" "<<val2[i]<<endl;
            if(val[i] != INT_MAX && val2[i] != INT_MAX)
            {
                if(ans > max(val[i] , val2[i]))
                {
                    ans = max(val[i] , val2[i]);
                    res = i;
                }
                
            }
        }
        return res;
    }
};