class Solution {
private:
    int n;
    vector<long long>dp;
    long long rec(int i,vector<int>&nums,vector<int>&colors){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        long long nt = rec(i+1,nums,colors);
        long long take = 0;

        if((i< n-1) && colors[i] == colors[i+1]){
            take = nums[i] + rec(i+2,nums,colors);
        }
        else{
            take = nums[i] + rec(i+1,nums,colors);
        }
        return dp[i] = max(take,nt);
    }
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        n = nums.size();
        long long ans = 0;
        dp.assign(n,-1);
        return rec(0,nums,colors);
    }
};