class Solution {
private:
    // int rec(int i,int n,int pre,vector<int>&arr,vector<vector<int>>&dp)
    // {
    //     if(i == n) return 0;
    //     if(dp[i][pre+1] != -1) return dp[i][pre+1];
    //     int t = 0;
    //     if(pre ==-1 || arr[i] > arr[pre]) t =1 + rec(i+1,n,i,arr,dp);
    //     int nt = rec(i+1,n,pre,arr,dp);
    //     return dp[i][pre+1] = max(t,nt);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i = n-1;i>=0;i--)
        {
            for(int j=i-1;j>=-1;j--)
            {
                int t = 0;
                if(j == -1 || nums[i] > nums[j]) t = 1+ dp[i+1][i+1];
                int nt = dp[i+1][j+1];
                dp[i][j+1] = max(nt,t);
            }
        }
        return dp[0][0];
    }
};