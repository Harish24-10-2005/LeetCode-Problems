class Solution {
private:
    long long k,n;
    unordered_map<string,long long>dp;
    int rec(int i,long long mul,long long div,vector<int>&nums){
        long long g = gcd(mul, div);
        mul /= g;
        div /= g;
        if(i == n){
            if(div == 1 && mul == k) return 1;
            return 0;
        }
        string key = to_string(i)+"#"+ to_string(mul)+"#"+ to_string(div);
        if(dp.count(key)) return dp[key];
        return dp[key] = {rec(i+1,mul *nums[i],div,nums) + rec(i+1,mul,div * nums[i],nums) + rec(i+1,mul,div,nums)};
    }
public:
    int countSequences(vector<int>& nums, long long K) {
        n = nums.size();
        k = K;
        return rec(0,1,1,nums);
    }
};