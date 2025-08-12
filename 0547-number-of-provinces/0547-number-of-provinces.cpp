class Solution {
private:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj)
    {
        vis[node] = 1;
        for(int i:adj[node])
        {
            if(vis[i] == 0)
            {
                dfs(i,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};