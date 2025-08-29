class Solution {
private:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&path,vector<int>&vis)
    {
        path[node] = 1;
        vis[node] = 1;
        for(int i:adj[node])
        {
            if(vis[i] != 1)
            {
                dfs(i,adj,path,vis);
            }
            if(path[i] == 1) return false;
        }
        path[node] = 0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>path(numCourses);
        vector<int>vis(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            if(!dfs(i,adj,path,vis)) return false;
        }
        return true;
    }
};