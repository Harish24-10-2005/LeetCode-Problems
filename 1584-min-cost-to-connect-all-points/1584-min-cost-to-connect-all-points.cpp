class Dis{
private :
    vector<int>par;
    vector<int>size;
public :
    Dis(int n)
    {
        par.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }

    }
    int findpar(int n)
    {
        if(par[n] == n) return n;
        return par[n] = findpar(par[n]);
    }
    void unionBysize(int u,int v)
    {
        int paru = findpar(u);
        int parv = findpar(v);
        if(paru == parv) return;
        if(size[paru] < size[parv]) {
            par[paru] = parv;
            size[parv] += size[paru];
        } else {
            par[parv] = paru;
            size[paru] += size[parv];
        }

    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        vector<pair<int,pair<int,int>>>all;
        int n = p.size();
        for(int i=0;i<n;i++)
        {
            int u = p[i][0];
            int v = p[i][1];
            for(int j=i+1;j<n;j++)
            {
                int x = p[j][0];
                int y = p[j][1];
                int temp = abs(u-x) + abs(v-y);
                all.push_back({temp,{i,j}});
            }
        }
        sort(all.begin(),all.end());
        Dis d(p.size());
        int ans = 0;
        for(int i=0;i<all.size();i++)
        {
            int u = all[i].second.first;
            int v = all[i].second.second;
            int c = all[i].first;
            int pu = d.findpar(u);
            int pv = d.findpar(v);
            if(pu != pv)
            {
                d.unionBysize(u,v);
                ans+=c;
            }
        }
        return ans;
    }
};