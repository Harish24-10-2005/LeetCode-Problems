class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int,int>mpp;
        for(auto a:power)
        {
            mpp[a]++;
        }
        vector<int>val;
        for(auto a:mpp) val.push_back(a.first);

        vector<long long >dp(val.size(),0);
        if(val.size() == 1) return val[0]*mpp[val[0]];
        dp[0] = val[0]*mpp[val[0]];
        if((val[1] - val[0]) > 2)
        {
            dp[1] = dp[0] + 1LL*val[1]*mpp[val[1]];
        }
        else
        {
            dp[1] = max(dp[0], 1LL *val[1] * mpp[val[1]]);
        }

        for(int i = 2;i<val.size();i++)
        {
            long long t = 1LL*val[i]*mpp[val[i]];

            int j = i -1;
            while(j >= 0 && (val[i] - val[j]) <= 2) j--;
            if(j >= 0) t += dp[j];

            dp[i] = max(dp[i-1],t);
        }
        return dp.back();
    }
};