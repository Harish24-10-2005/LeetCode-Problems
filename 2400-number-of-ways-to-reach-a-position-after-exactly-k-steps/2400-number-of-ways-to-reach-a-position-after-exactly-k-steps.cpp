class Solution {
private:
    int end;
    int MOD = 1e9 + 7;
    unordered_map<string,int>dp;
    int rec(int i,int k){
        if(i == end && k == 0) return 1;
        if(k == 0){
            return 0;
        }
        if (abs(i - end) > k) return 0;
        string key = to_string(i) + "#" + to_string(k);
        if(dp.count(key)) return dp[key];
        int lft = rec(i+1,k-1) % MOD;
        int ryt = rec(i-1,k-1) % MOD;
        return dp[key] = (lft + ryt) % MOD;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        end = endPos;
        return rec(startPos,k);
    }
};