class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int>lps(n,0);
        for(int i=1;i<n;i++)
        {
            int pre = lps[i-1];
            while(pre > 0 && s[i] != s[pre])
            {
                pre = lps[pre-1];
            }
            lps[i] = pre + (s[i] == s[pre] ? 1:0);
        }
        // for(auto a:lps)
        // {
        //     cout<<a<<endl;
        // }
        int l = lps.back();
        return s.substr(0,l);
    }
};