class Solution {
private:
    void createadj(vector<vector<int>>&edges,int n,vector<vector<int>>&adj)
    {
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void dfs(int node,vector<vector<int>>&adj,int& last,int d,int& md,vector<int>&vis)
    {
        vis[node] = 1;
        if(d > md)
        {
            md = d;
            last = node;
        }
        for(int i:adj[node])
        {
            if(vis[i] == 0)
            {
                dfs(i,adj,last,d+1,md,vis);
            }
        }
    }
    void dfs2(int node,vector<vector<int>>&adj,int& m,int l,vector<int>&vis)
    {
        vis[node] = 1;
        l+=1;
        m = max(m,l);
        // cout<<node<<" "<<m<<endl;
        for(int i:adj[node])
        {
            if(vis[i] == 0)
            {
                dfs2(i,adj,m,l,vis);
            }
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(m);
        createadj(edges1,n,adj1);
        createadj(edges2,m,adj2);
        int l1 = 0;
        int l2 = 0;

        vector<int>vis(n,0);
        int md = -1;
        dfs(0,adj1,l1,0,md,vis);
        vis.assign(m,0);
        md = -1;
        dfs(0,adj2,l2,0,md,vis);

        // cout<<l1<<endl<<l2<<endl;
        int m1 = 0;
        int m2 = 0;
        
        vis.assign(n,0);
        dfs2(l1,adj1,m1,0,vis);
        // cout<<"................."<<endl;
        vis.assign(m,0);
        dfs2(l2,adj2,m2,0,vis);

        // cout<<m1<<endl<<m2<<endl;
        m1--;
        m2--;
        int res1 = m1/2;
        int res2 = m2/2;

        if(m1%2!=0) res1+=1;
        if(m2%2!=0) res2+=1;

        return max({m1,m2,res1 + res2 + 1});
    }
};