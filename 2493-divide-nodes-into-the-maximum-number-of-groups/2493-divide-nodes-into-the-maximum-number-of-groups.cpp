class Solution {
private:
    int n;
    vector<vector<int>>adj;
    int bfs(int node){
        int ans = 1;
        vector<int>dist(n+1,-1);
        queue<vector<int>>q;
        dist[node] = 1;
        q.push({node,-1});

        while(!q.empty()){
            int si = q.size();
            for(int j=0;j<si;j++){
                int u = q.front()[0];
                int par = q.front()[1];
                q.pop();
                ans = max(ans,dist[u]);

                for(auto v:adj[u]){
                    if(v == par) continue;
                    if(dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        q.push({v,node});
                    }
                    else if(abs(dist[u] - dist[v]) == 1){
                        continue;
                    }
                    else{
                        // cout<<u<<"<->"<<v<<endl;
                        return -1;
                    }
                }
            }
        }
        return ans;
    }
public:
    int magnificentSets(int num, vector<vector<int>>& edges) {
        n = num;
        int t = 0;
        adj.resize(n+1);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        vector<int>vis(n+1,-1);
        for(int i=1;i<=n;i++){
            if(vis[i] == -1){
                vector<int>nodes;
                queue<pair<int,int>>q;
                q.push({i,0});
                vis[i] = 0;
                while(!q.empty()){
                    int u = q.front().first;
                    int l = q.front().second;
                    q.pop();
                    nodes.push_back(u);
                    for(int i:adj[u]){
                        if(vis[i] == -1){
                            vis[i] = l+1;
                            q.push({i,l+1});
                        }
                        else if(vis[u] == vis[i]) return -1;
                    }
                }
                int maxx= 0;
                for(int node:nodes){
                    // cout<<node<<" ";
                    int temp = bfs(node);
                    if(temp == -1) return -1;
                    maxx = max(maxx,temp);
                }
                // cout<<endl;
                t = t+maxx;
            }
        }
        return t;
    }
};