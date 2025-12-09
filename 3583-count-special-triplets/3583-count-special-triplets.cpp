class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        int MOD = 1e9 + 7;
        unordered_map<int,int>before,after;
        for(auto a:nums) after[a]++;
        for(auto a:nums){
            after[a]--;
            int be = before[a*2];
            int af = after[a*2];
            ans = ans + ((be * af) % MOD) % MOD;
            before[a]++;
        }
        return ans;
    }
};