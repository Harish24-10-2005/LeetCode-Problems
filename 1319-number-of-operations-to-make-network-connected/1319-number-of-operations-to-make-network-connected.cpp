class Disjoint{
private: 
    vector<int>size,par;
public :
    Disjoint(int n)
    {
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i] = i;
        }
    }
    int find(int x)
    {
        if(x == par[x])
        {
            return x;
        }
        return par[x] = find(par[x]);
    }
    void unionSize(int x,int y)
    {
        int ulp_x = find(x);
        int ulp_y = find(y);
        if(ulp_x == ulp_y) return; 
        if(size[ulp_x]<size[ulp_y])
        {
            size[ulp_y]+=size[ulp_x];
            par[ulp_x] = ulp_y;
        }
        else
        {
            size[ulp_x]+=size[ulp_y];
            par[ulp_y] = ulp_x;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint d(n);
        int cnt =0;
        for(auto a:connections)
        {
            int u = a[0];
            int v = a[1];
            if(d.find(u) == d.find(v))
            {
                cnt++;
            }
            else d.unionSize(u,v);
        }
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(d.find(i) == i) c++;
        }
        int need = c-1;
        return (cnt >= need) ? need:-1;
    }
};