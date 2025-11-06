class Disjoint{
public:
    vector<int>size;
    vector<int>par;
    Disjoint(int n){
        size.resize(n);
        par.resize(n);
        for(int i=0;i<n;i++)
        {
            size[i] = 1;
            par[i] = i;
        }
    }
    int findpar(int node){
        if(node == par[node]) return node;
        return par[node] = findpar(par[node]);
    }
    void unionBysize(int u,int v){
        int up = findpar(u);
        int vp = findpar(v);
        if(size[up]<size[vp])
        {
            par[up] = par[vp];
            size[vp]+=size[up];
        }
        else{
            par[vp] = par[up];
            size[up]+=size[vp];
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        Disjoint d(c+1);
        for(auto a:connections)
        {
            int u = a[0];
            int v = a[1];
            int up = d.findpar(u);
            int vp = d.findpar(v);
            if(up != vp)
            {
                d.unionBysize(up,vp);
            }
        }
        unordered_map<int,set<int>>mpp;

        for(int i=1;i<=c;i++)
        {
            int p = d.findpar(i);
            mpp[p].insert(i);
        }
        vector<int>vis(c+1,1);
        vector<int>res;
        for(auto a:queries)
        {
            int c = a[0];
            int node = a[1];
            int p = d.findpar(node);
            if(c == 1){
                if(vis[node] == 1) res.push_back(node);
                else{
                    bool f = false;
                    for(auto& a:mpp[p])
                    {
                        if(vis[a] == 1)
                        {
                            f = true;
                            res.push_back(a);
                            break;
                        }
                    }
                    if(!f) res.push_back(-1);
                }
            }
            else{
                vis[node] = 0;
                mpp[p].erase(node);
            }
        }
        return res;
    }
};