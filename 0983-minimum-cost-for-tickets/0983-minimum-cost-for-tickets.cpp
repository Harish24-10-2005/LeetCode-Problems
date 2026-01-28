class Solution {
private:
    int n;
    vector<vector<int>>dp;
    int rec(int i,int en,vector<int>&d,vector<int>&c){
        while(i < n && d[i]< en) i++;
        if(i >= n){
            return 0;
        }
        if(dp[i][en] != -1) return dp[i][en];
        return dp[i][en] = min({
            c[0] + rec(i,d[i] + 1,d,c),
            c[1] + rec(i,d[i] + 7,d,c),
            c[2] + rec(i,d[i] + 30,d,c)
        });

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        sort(days.begin(),days.end());
        dp.assign(n,vector<int>(days[n-1] + 1,-1));
        return rec(0,days[0],days,costs);
    }
};