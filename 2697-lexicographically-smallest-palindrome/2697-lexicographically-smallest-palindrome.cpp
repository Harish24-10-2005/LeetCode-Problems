class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int i = n/2;
        string res = "";
        string d = s.substr(0,i);
        string m = "";
        if(n%2 != 0)
        {
            m = s[n/2];
            i++;
        }
        string f = s.substr(i,n);
        // cout<<d<<endl<<m<<endl<<f<<endl;
        for(int i=0;i<n/2;i++)
        {
            if(d[i] == f[(n/2)-i-1]) res+= d[i];
            else res+=(d[i] < f[(n/2)-i-1] ? d[i] : f[(n/2)-i-1]);
        }
        d = res;
        reverse(res.begin(),res.end());
        return d + m + res;
    }
};