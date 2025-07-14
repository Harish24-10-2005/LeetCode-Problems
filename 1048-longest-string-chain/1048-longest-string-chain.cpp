class Solution {
private:
    bool compare(string s,string p)
    {
        if(s.size()-1 != p.size()) return false;
        int i=0;
        int j=0;
        while(i<s.size())
        {
            if(j<p.size() && s[i] == p[j]) 
            {
                i++;
                j++;
            }
            else i++;
        }
        return j == p.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(),words.end(),[](string &a,string&b){
            return a.size() < b.size();
        });
        vector<int>dp(n,1);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(words[i],words[j]) && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j] +1;
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};