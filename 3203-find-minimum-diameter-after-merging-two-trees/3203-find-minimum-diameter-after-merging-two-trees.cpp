class Solution {
private :
    void findD(int node,int dis,int par,vector<vector<int>>&adj,pair<int,int>&res)
    {
        if(dis>res.first)
        {
            res.first = dis;
            res.second = node;
        }
        for(int i:adj[node])
        {
            if(i!=par)
            {
                findD(i,dis+1,node,adj,res);
            }
        }
    }
    void buildG(vector<vector<int>>& edges,vector<vector<int>>&adj)
    {
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>>g1(edges1.size()+1);
        vector<vector<int>>g2(edges2.size()+1);
        buildG(edges1,g1);
        buildG(edges2,g2);

        pair<int,int>res1 = {INT_MIN,-1};
        pair<int,int>res2 = {INT_MIN,-1};
        findD(0,0,-1,g1,res1);
        findD(res1.second,0,-1,g1,res2);
        int d1 = res2.first;

        res1 = {INT_MIN,-1};
        res2 = {INT_MIN,-1};
        findD(0,0,-1,g1,res1);
        findD(res1.second,0,-1,g1,res2);
        int d2 = res2.first;

        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};