class Solution {
    int n;
    vector<int>vis;
private:
    bool bfs(int n,vector<vector<int>>& graph)
    {
        queue<pair<int,int>>q;
        q.push({n,0});
        vis[n] = 0;
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            int node = a.first;
            int val = a.second;
            for(auto i:graph[node])
            {
                if(vis[i] == -1)
                {
                    vis[i] = !val;
                    q.push({i,!val});
                }
                else if(vis[i] == val) return false;
            }
        }   
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vis.assign(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i] == -1 && !bfs(i,graph)) return false;
        }
        return true;
    }
};