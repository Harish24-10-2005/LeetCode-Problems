class Solution {
private:
    int rec(int i,int a,vector<int>&c,vector<vector<int>>&dp)
    {
        if(a == 0) return 0;
        if(i == c.size()) return INT_MAX;
        if(dp[i][a] != -1) return dp[i][a];
        int take = INT_MAX;
        if(a-c[i] >= 0)
        {
            int temp = rec(i,a - c[i],c,dp);
            if(temp !=INT_MAX)
            {
                take = 1 + temp;
            }
        }
        int nt = rec(i+1,a,c,dp);
        return dp[i][a] = min(nt,take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = rec(0,amount,coins,dp);
        return ans == INT_MAX ? -1 :ans;
    }
};