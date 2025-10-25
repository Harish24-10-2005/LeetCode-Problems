class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>d(n);
        for(auto a:roads)
        {
            int u = a[0];
            int v = a[1];
            d[v]++;
            d[u]++;
        }
        sort(d.begin(),d.end(),greater<int>());
        long long ans = 0;
        for(auto a:d)
        {
            // cout<<a<<endl;
            ans += (long long)a * n;
            n--;
        }
        return ans;
    }
};