class Solution {
private:
    vector<vector<int>>dp;
    int rec(int i,int j,string & s1,string& s2){
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = INT_MIN;
        if(s1[i] == s2[j]){
            take = s1[i] + rec(i+1,j+1,s1,s2);
        }
        return dp[i][j] = max({take,rec(i+1,j,s1,s2),rec(i,j+1,s1,s2)});
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        // unordered_set<int>idx1,idx2;
        int n = s1.size();
        int m = s2.size();
        dp.assign(n,vector<int>(m,-1));
        int ans = 0;
        for(int i = 0;i<max(n,m);i++){
            if(i < s1.size()){
                ans+= s1[i];
            }
            if(i < s2.size()){
                ans+= s2[i];
            }
        }
        int same = rec(0,0,s1,s2);
        return ans - (2*same);
    }
};