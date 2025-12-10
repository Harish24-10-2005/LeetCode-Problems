class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int MOD = 1e9 + 7;
        int num = complexity[0];
        sort(complexity.begin(),complexity.end());
        if(n >= 1 && (num != complexity[0] || complexity[0] == complexity[1])) return 0;
        if(n-1 == 0 || n-1 == 1)return 1; 
        int f = 2;
        for(int i=3;i<=n-1;i++){
            f = 1LL * f * i % MOD;
        }
        return f;
    }
};