class Solution {
private:
    bool dfs(int i,vector<int>&vis,vector<int>&path,vector<vector<int>>&adj)
    {
        vis[i] = 1;
        path[i] = 1;
        for(int node:adj[i])
        {
            if(vis[node] == 0)
            {
                if(dfs(node,vis,path,adj))
                {
                    return true;
                }
            }
            if(path[node] == 1)
            {
                return true;
            }
        }
        path[i] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<p.size();i++)
        {
            int u = p[i][0];
            int v = p[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(numCourses),path(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            if(dfs(i,vis,path,adj))
            {
                return false;
            }
        }
        return true;
    }
};