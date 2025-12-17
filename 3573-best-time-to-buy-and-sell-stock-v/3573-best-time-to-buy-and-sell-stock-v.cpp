class Solution {
private:
    int n;
    vector<vector<vector<vector<long long>>>>dp;
    long long rec(int i,bool buy,bool type,int k,vector<int>&p){
        if(k == 0) return 0;
        if(i == n)
        {
            if(type) return LLONG_MIN;
            return 0;
        }
        if(dp[i][k][buy][type] != -1) return dp[i][k][buy][type];
        long long ans = LLONG_MIN;
        if(buy){
            ans = -p[i] + rec(i+1,false,false,k,p);
            long long temp = rec(i+1,false,true,k,p);
            if(temp != LLONG_MAX) ans = max(ans,p[i] + temp);
        }
        else{
            if(type){
                ans = -p[i] + rec(i+1,true,false,k-1,p);
            }
            else{ 
                ans = p[i] + rec(i+1,true,false,k-1,p);
            }
        }
        ans = max(ans,rec(i+1,buy,type,k,p));
        return dp[i][k][buy][type] = ans;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.assign(n,vector<vector<vector<long long>>>(k+1,vector<vector<long long>>(2,vector<long long>(2,-1))));
        return rec(0,true,false,k,prices);
    }
};