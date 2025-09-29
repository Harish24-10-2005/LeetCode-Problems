class Solution {
    vector<vector<int>>adj;
    vector<int>vis;
private:
    long long bfs(int node,vector<int>&nums)
    {
        queue<int>q;
        vector<int>res;
        q.push(node);
        int e = 0;
        int o = 0;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            res.push_back(nums[n]);
            if(n%2 == 0) e++;
            else o++;
            for(int i:adj[n])
            {
                if(!vis[i])
                {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        sort(res.begin(),res.end(),greater<int>());
        // cout<<res.size()<<endl<<e<<endl<<o<<endl;
        int i = 0;
        long long e_cnt = 0;
        long long o_cnt = 0;
        while(e--)
        {
            e_cnt+=res[i];
            // cout<<i<<endl;
            i++;
        }
        while(o--)
        {
            // cout<<i<<endl;
            o_cnt+=res[i];
            i++;
        }
        return e_cnt - o_cnt;
    }
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        adj.resize(n);
        for(auto a:swaps)
        {
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long ans = 0;
        vis.assign(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ans+=bfs(i,nums);
            }
        }   
        return ans;
    }
};