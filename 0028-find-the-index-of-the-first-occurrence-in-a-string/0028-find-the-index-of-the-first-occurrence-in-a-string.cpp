#define ll long long
class Solution {
    ll MOD1 = 1e9 + 7;
    ll MOD2 = 1e9 + 33;
    ll R1 = 26;
    ll R2 = 27;
private:
    pair<ll,ll> findhash(string s)
    {
        ll hash1 = 0,hash2 = 0;
        ll f1 = 1,f2 = 1;
        for(int i=s.size()-1;i>=0;i--)
        {
            hash1 = (hash1 + (s[i] - 'a')*f1) % MOD1;
            f1 = ((f1 * R1)%MOD1); 
            hash2 = (hash2 + (s[i] - 'a')*f2) % MOD2;
            f2 = ((f2 * R2)%MOD2); 
        }
        return {hash1,hash2};
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        ll m1 = 1;
        ll m2 = 1;
        for(int i=0;i<m;i++)
        {
            m1 = (m1*R1)%MOD1;
            m2 = (m2*R2)%MOD2;
        }
        pair<ll,ll>hash = findhash(needle);

        pair<ll,ll>res{0,0};
        for(int i=0;i<=n-m-1;i++)
        {
            if(i == 0)
            {
                res = findhash(haystack.substr(0,m));
            }
            else
            {
                res.first = ((res.first- ((haystack[i-1]-'a')*m1 %MOD1)+MOD1)*R1 + (haystack[i+m-1]-'a'))%MOD1;
                res.second = ((res.second - ((haystack[i-1]-'a')*m2 %MOD2) + MOD2)*R2 +(haystack[i+m-1]-'a'))%MOD2;
            }
            if(res.first == hash.first && res.second == hash.second) return i;
        }
        return -1;
    }
};