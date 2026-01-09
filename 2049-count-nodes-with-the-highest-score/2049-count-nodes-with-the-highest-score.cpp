class Solution {
    typedef long long ll;
private:
    vector<ll>sub;
    vector<vector<int>>adj;
    unordered_map<long long,int>mpp;
    vector<ll>newsub;
    int res = INT_MIN;
    int dfs(int node,int par){
        int si = 1;
        for(int i:adj[node]){
            if(i == par)continue;
            si += dfs(i,node);
        }
        sub[node] = si;
        return si;
    }
    void dfs2(int node,int par){
        long long curr = 1;
        for(int i:adj[node]){
            if(i == par) {
                curr*= 1LL * (newsub[par] - sub[node]);
                continue;
            }
            curr *= sub[i];
            // cout<<node<<" : "<<i<<" "<<sub[i]<<endl;
            newsub[i] =  sub[i]  + (newsub[node] - sub[i]);
            dfs2(i,node);
        }
        // cout<<"node :"<<node<<" val: "<<curr<<endl;
        mpp[curr]++;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        adj.resize(n);
        sub.resize(n);
        newsub.resize(n);
        for(int i = 1;i<n;i++){
            adj[parents[i]].push_back(i);
            adj[i].push_back(parents[i]);
        }
        dfs(0,-1);
        newsub[0] = sub[0];
        dfs2(0,-1);
        int res = 0;
        ll maxx = INT_MIN;
        for(auto a:mpp){
            if(a.first > maxx){
                maxx = a.first;
                res = a.second;
            }
        }
        return res;
    }
};