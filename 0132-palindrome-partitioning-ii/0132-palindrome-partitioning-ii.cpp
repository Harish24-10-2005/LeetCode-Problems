class Solution {
private:
    vector<int>dp;
    bool pal(string& s,int i,int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int rec(int idx,string& s)
    {
        if(idx == s.size())
        {
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        // cout<<s.substr(idx)<<endl;
        int ans = INT_MAX;
        for(int i= idx;i<s.size();i++)
        {
            if(pal(s , idx , i))
            {
                ans = min(ans,1 + rec(i+1,s)); 
            }
        }
        return dp[idx] = ans;
    }
public:
    int minCut(string s) {
        dp.assign(s.size(),-1);
        return rec(0,s)-1;
    }
};