class Solution {
    vector<vector<vector<long long>>>dp;
    long long rec(int i,int j,int k,vector<int>&n1,vector<int>&n2){
        if(k == 0)return 0;
        if(i >= n1.size() || j >= n2.size()) return LLONG_MIN;

        if(dp[i][j][k] != -1e18) return dp[i][j][k];

        long long temp =rec(i+1,j+1,k-1,n1,n2);
        long long take = LLONG_MIN;
        if(temp != LLONG_MIN) take =(1LL* n1[i] * n2[j]) +  temp;
        long long nt1 = rec(i,j+1,k,n1,n2);
        long long nt2 = rec(i+1,j,k,n1,n2);

        return dp[i][j][k] = max({take,nt1,nt2});
        // return max({take,nt1,nt2});
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        dp.assign(nums1.size(),vector<vector<long long>>(nums2.size(),vector<long long>(k+1,-1e18)));
        return rec(0,0,k,nums1,nums2);
    }
};