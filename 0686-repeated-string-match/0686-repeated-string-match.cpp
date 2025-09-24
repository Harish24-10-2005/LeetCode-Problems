#define ll long long
class Solution {
private:
    ll r1 = 26;
    ll r2 = 27;
    ll MOD1 = 1e9+7;
    ll MOD2 = 1e9+33;
    pair<ll,ll>hash(string s)
    {   
        int n = s.size();
        ll hash1 = 0;
        ll hash2 = 0;
        ll f1 = 1;
        ll f2 = 1;
        for(int i=n-1;i>=0;i--)
        {
            hash1 = (hash1 + (s[i]-'a')*f1)%MOD1;
            f1 = (f1*r1)%MOD1;

            hash2 = (hash2 + (s[i]-'a')*f2)%MOD2;
            f2 = (f2*r2)%MOD2;
        }
        return {hash1,hash2};
    }
    int rabinkarp(string a,string b)
    {
        int n = a.size();
        int m = b.size();
        pair<ll,ll>pat = hash(b);
        ll hash1 = 0;
        ll hash2 = 0;
        ll m1 = 1;
        ll m2 = 1;
        for(int i=1;i<m;i++)
        {
            m1 = (m1*r1)%MOD1;
            m2 = (m2*r2)%MOD2;
        }
        for(int i=0;i<=n-m;i++)
        {
            if(i == 0)
            {
                auto s = hash(a.substr(0,m));
                hash1 = s.first;
                hash2 = s.second;
            }
            else
            {
                hash1 = (hash1 - (a[i-1]-'a')*m1)%MOD1;
                hash2 = (hash2 - (a[i-1]-'a')*m2)%MOD2;

                if(hash1 < 0) hash1 += MOD1;
                if(hash2 < 0) hash2 += MOD2;

                hash1 = (hash1*r1 + (a[i+m-1] - 'a'))%MOD1;
                hash2 = (hash2*r2 + (a[i+m-1] - 'a'))%MOD2;
            }
            if(hash1 == pat.first && hash2 == pat.second) return i;
        }
        return -1;
    }
public:
    int repeatedStringMatch(string a, string b) {
        string t = a;
        int ans = 1;
        while(a.size() <= 2*b.size() )
        {
            if(a.size() >= b.size() && rabinkarp(a,b) != -1)
            {
                return ans;
            }
            a+=t;
            ans++;
        }
        return -1;
    }
};