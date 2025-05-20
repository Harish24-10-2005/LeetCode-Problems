class Solution {
    private:
    int time = 0;
    void findb(int node,int p,vector<int>&vis,vector<int>&t,vector<int>&l,vector<vector<int>>&adj,vector<vector<int>>&b)
    {
        vis[node] = 1;
        t[node] = l[node] = time;
        time++;
        for(int i:adj[node])
        {
            if(i == p) continue;
            if(vis[i]!=1)
            {
                findb(i,node,vis,t,l,adj,b);
                l[node] = min(l[i],l[node]);
                if(l[i] > t[node])
                {
                    b.push_back({node,i});
                }
            }
            else
            {
                l[node] = min(l[i],l[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>b;
        vector<vector<int>>adj(n);

        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int>t(n),l(n);
        vector<int>vis(n,0);
        findb(0,-1,vis,t,l,adj,b);
        return b;
    }
};