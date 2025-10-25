class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>o(n+1,0);
        vector<int>in(n+1,0);
        for(auto a:trust)
        {
            int u = a[0];
            int v = a[1];
            o[u]++;
            in[v]++;
        }
        for(int i=1;i<=n;i++)
        {
            if((o[i] == 0 && in[i] == n-1) || o[i] == 0) return i;
        }
        return -1;
    }
};