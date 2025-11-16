class Solution {
    const long long MOD = 1e9 + 7;
public:
    int numSub(string s) {
        int n = s.size();
        int ans = 0;
        int o = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                // cout<<o<<endl;
                ans = (ans  + (o% MOD * (o + 1)% MOD / 2) % MOD) % MOD;
                // cout<<ans<<endl;
                o = 0;
            }
            else o++;
        }
        if(o > 0) ans = (ans + (o% MOD * (o + 1)% MOD / 2) % MOD) % MOD;
        return ans;
    }
};