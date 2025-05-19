class Dis{
    private:
    vector<int>size,par;
    public:
    Dis(int n)
    {
        size.resize(n,1);
        par.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i] = i;
        }
    }
    int findpar(int x)
    {
        if(x == par[x]) return x;
        return par[x] = findpar(par[x]);
    }
    void unionbysize(int x,int y)
    {
        int ux = findpar(x);
        int uy = findpar(y);
        if(ux == uy) return;
        if(size[ux] > size[uy])
        {
            par[uy] = ux;
            size[ux]+=size[uy];
        }
        else
        {
            par[ux] = uy;
            size[uy]+=size[ux];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxr = 0;
        int maxc = 0;
        for(auto a:stones)
        {
            maxr = max(maxr,a[0]);
            maxc = max(maxc,a[1]);
        }
        Dis d(maxc+maxr+2);
        set<int>nodes;
        for(auto a:stones)
        {
            int row = a[0];
            int col = a[1] + maxr + 1;
            d.unionbysize(row,col);
            nodes.insert(row);
            nodes.insert(col);
        }
        int cnt =0;
        for(int i:nodes)
        {
            if(d.findpar(i) == i)cnt++;
        }
        return stones.size()-cnt;
    }
};