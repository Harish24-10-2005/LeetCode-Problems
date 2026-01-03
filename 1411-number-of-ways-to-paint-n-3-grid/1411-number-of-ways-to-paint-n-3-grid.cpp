class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numOfWays(int n) {
        int aba = 6;
        int abc = 6;
        for(int i=2;i<=n;i++){
            long long n_aba = ((1LL * 2 * abc) + (1LL *3 * aba)) %MOD;
            long long n_abc = ((1LL * 2 * abc) + (1LL *2 * aba)) % MOD;
            aba = n_aba ;
            abc = n_abc ; 
        }
        return (aba + abc)% MOD;
    }
};