class Solution {
    int MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();

        vector<int>res;
        vector<int>predigit(n,0);
        vector<int>precnt(n,-1);
        vector<int>presum(n,-1);

        int pred = 0;
        int pre = 0;
        int cnt = (s[0] -'0') == 0 ? 0 : 1;
        presum[0] = s[0] -'0';
        predigit[0] = s[0] -'0';
        precnt[0] = cnt;

        for(int i=1;i<n;i++)
        {
            presum[i] = presum[i-1] + (s[i] - '0');
            if((s[i] -'0') != 0)
            {
                predigit[i] = ( (predigit[i-1] * 10LL) % MOD + (s[i] - '0') ) % MOD;
                cnt++;
            }
            else
            {
                predigit[i] = predigit[i-1];
            }
            precnt[i] = cnt;
        }

        // for(auto a:precnt)
        // {
        //     cout<<a<<endl;
        // }
        vector<long long> pow10(n+1);
        pow10[0] = 1;
        for(int i = 1; i <= n; i++)
            pow10[i] = (pow10[i-1] * 10) % MOD;

        for(auto q:queries)
        {
            int st = q[0];
            int end = q[1];

            int ans = predigit[end];
            int d = precnt[end];
            int summ = presum[end];

            if(st-1 >= 0)
            {
                int d_len = d - precnt[st-1];
                if(d_len == 0)
                {
                    res.push_back(0);
                    continue;
                }
                long long re = (predigit[st-1] * pow10[d_len]) % MOD;
                ans = (predigit[end] - re + MOD) % MOD;
                summ -= presum[st-1];
            }
            // cout<<ans<<" "<<summ<<endl;
            ans = ( (1LL * (ans % MOD) * (summ % MOD)) % MOD );
            res.push_back(ans);
        }
        return res;
    }
};