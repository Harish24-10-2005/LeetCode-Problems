class Solution {
private:
    // bool rec(int i,string s,vector<string>&mpp)
    // {
    //     if(i>=s.size()) return true;
    //     for(auto a:mpp)
    //     {
    //         // cout<<s.substr(i,a.size())<<"  -> "<<a<<endl;
    //         if(s.size() < i+a.size()) continue;
    //         if(s.substr(i,a.size()) == a && rec(i+a.size(),s,mpp))
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,0);
        dp[0] = 1;
        
        for(int i=0;i<s.size();i++)
        {
            if(!dp[i]) continue;
            for(auto a:wordDict)
            {
                int l = a.size();
                if(i+l<=s.size() && s.substr(i,l) == a)
                {
                    dp[i+l] = 1;
                }
            }
        }
        return dp[s.size()];
    }
};