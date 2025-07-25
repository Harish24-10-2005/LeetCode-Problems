class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0;
        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            int l=i;int r = i;
            while(l>=0 && r<n && s[l] == s[r])
            {
                if(maxx < r-l+1)
                {
                    st = l;
                    maxx = r-l+1;
                }
                l--;r++;
            }
            l = i;r = i+1;
            while(l>=0 && r<n && s[l] == s[r])
            {
                if(maxx < r-l+1)
                {
                    st = l;
                    maxx = r-l+1;
                }
                l--;r++;
            }
        }
        return s.substr(st,maxx);
    }
};