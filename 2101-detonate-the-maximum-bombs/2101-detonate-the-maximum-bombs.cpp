class Solution {
private:
    int bfs(int idx,vector<vector<int>>&b,vector<int>&vis){
        queue<int>q;
        // int x = b[idx][0];
        // int y = b[idx][1];
        // int r = b[idx][2];
        int ans = 1;
        q.push(idx);
        vis[idx] =1;
        while(!q.empty()){
            int id = q.front();
            q.pop();
            int x = b[id][0];
            int y = b[id][1];
            int r = b[id][2];
            for(int i=0;i<b.size();i++){
                if(vis[i] == 1 || i == idx) continue;
                int nx = b[i][0];
                int ny = b[i][1];
                long long dist = pow(nx - x, 2) + pow(ny - y, 2);
                // cout<<dist<<endl;
                long long sq = 1LL *r * r;
                if(dist <= sq){
                    q.push(i);
                    vis[i] = 1;
                    ans++;
                }
            }
        }
        return ans;

    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int>vis(n,0);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            ans = max(ans,bfs(i,bombs,vis));
        }
        return ans;
    }
};