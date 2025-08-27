class Solution {
private:
    void ex(string s,int l,int r,int &st,int &maxx)
    {
        while(l>=0 && r<s.size() && s[l] == s[r])
        {
            int len = r-l+1;
            if(len > maxx)
            {
                st = l;
                maxx = len;
            }
            l--;
            r++;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0;
        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            ex(s,i,i,st,maxx);
            ex(s,i,i+1,st,maxx);
        }
        return s.substr(st,maxx);
    }
};