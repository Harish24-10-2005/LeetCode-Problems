class Solution {
int rec(int i,int m,vector<int>&suff,vector<int>&p,vector<vector<int>>&dp){
    if(i == p.size()) return 0;
    if(i+2*m >= p.size()) return suff[i];
    if(dp[i][m] !=-1) return dp[i][m];
    int res = 0;
    for(int x=1;x<=2*m;x++)
    {
        res = max(res,suff[i] - rec(i+x,max(m,x),suff,p,dp));
    }
    return dp[i][m] = res;
}
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>suff(n);
        suff[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--) suff[i]=suff[i+1] + piles[i]; 
        return rec(0,1,suff,piles,dp);
    }
};