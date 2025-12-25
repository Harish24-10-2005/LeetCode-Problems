class Solution {
private:
    vector<vector<int>>adj;
    unordered_map<int,int>mpp;
    long long ans = 0;
    long long temp = 0;
    long long pre = 0;
    int dfs(int node,int grp,int par,vector<int>&g){
        int cnt = 0;
        if(grp == g[node]) cnt= 1;
        for(int i:adj[node]){
            if(i == par) continue;
            int sub = dfs(i,grp,node,g);
            cnt+=sub;
            int t= mpp[grp];
            int r= t- sub;
            ans+=1LL * r * sub;
        }
        return cnt;
    }
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        adj.resize(n);
        for(int i:group){
            mpp[i]++;
        }
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(auto a:mpp){
            vector<int>vis;
            if(a.second >= 2){
                dfs(0,a.first,-1,group);
            }
        }
        return ans;
    }
};