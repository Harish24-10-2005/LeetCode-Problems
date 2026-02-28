class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9 + 7;
        long long ans = 0;
        for(int i=1;i<=n;i++){
            int move = 0;
            for(int bit=0;bit<32;bit++){
                if((1<<bit) & i) move = bit;
            }
            ans = ((ans<<(move+1)) | i) % MOD;
        }
        return ans;
    }
};
