class Disjoint{
    private: 
    vector<int>par,size;
    public:
    Disjoint(int n)
    {
        par.resize(n);
        size.resize(n,1);
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
    void unionBysize(int x,int y)
    {
        int u_x = findpar(x);
        int u_y = findpar(y);
        if(u_x == u_y) return;
        if(size[u_x] < size[u_y])
        {
            size[u_y]+=size[u_x];
            par[u_x] = u_y;
        }
        else
        {
            size[u_x]+=size[u_y];
            par[u_y] = u_x;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint d(n);

        unordered_map<string,int>mpp;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mpp.find(accounts[i][j]) == mpp.end())
                {
                    mpp[accounts[i][j]] = i;
                }
                else
                {
                    d.unionBysize(i, mpp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>>mail(n);
        for(auto a:mpp)
        {
            int node = d.findpar(a.second);
            mail[node].push_back(a.first);
        }
        vector<vector<string>> res;
        for(int i=0;i<n;i++)
        {
            vector<string>temp{accounts[i][0]};
            if(mail[i].size() == 0) continue;
            sort(mail[i].begin(),mail[i].end());
            for(auto a:mail[i])
            {
                temp.push_back(a);
            }
            res.push_back(temp);
        }
        return res;
    }
};