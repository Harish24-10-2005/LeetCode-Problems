class Solution {
private:
    vector<pair<int,int>>temp;
    vector<vector<vector<int>>>dp;
    int rec(int i,int m,int n)
    {
        if(i == temp.size())
        {
            return 0;
        }
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int t = INT_MIN;
        int o = temp[i].first;
        int z = temp[i].second;
        if((m - z >= 0) && (n - o >=0))
        {
            t = 1 + rec(i+1,m-z,n-o);
        }
        int nt  = rec(i+1,m,n);
        return dp[i][m][n] = max(t,nt);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int si = strs.size();
        temp.resize(si);
        dp.assign(si,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        for(int i=0;i<si;i++)
        {
            int o = 0;
            int z = 0;
            for(auto a:strs[i])
            {
                if(a == '0')z++;
                else o++;
            }
            temp[i] = {o,z};
        }
        return rec(0,m,n);

    }
};