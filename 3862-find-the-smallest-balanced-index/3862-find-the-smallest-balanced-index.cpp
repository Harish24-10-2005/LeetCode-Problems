class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long summ =0;
        int MOD = 1e9 + 7;
        vector<long long>p(n+1,1);
        for(int i=n-1;i>=0;i--){
            p[i] = 1LL*p[i+1]*nums[i] % MOD;
        }
        for(int i=0;i<n;i++){
            if(summ == p[i+1]) return i;
            summ+=nums[i];
            summ = summ % MOD;
        }
        return -1;
    }
};