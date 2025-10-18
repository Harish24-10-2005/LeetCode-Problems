class Solution {
    int n;
private:
    pair<int,int> pal(int i,int j,string s)
    {
        while(i>=0 && j<n && s[i] == s[j])
        {
            i--;
            j++;
        }
        return {j-i,j};
    }
public:
    string shortestPalindrome(string s) {
        n = s.size();
        int r = 0;
        int maxx = 0;
        for(int i=0;i<n;i++)
        {
            auto a = pal(i,i,s);
            auto b = pal(i,i+1,s);
            if(a.first > maxx)
            {
                maxx = a.first;
                r = a.second;
            }
            if(b.first > maxx)
            {
                maxx = b.first;
                r = b.second;
            }
        }
        string t = s.substr(r);
        reverse(t.begin(),t.end());
        return t + s;
    }
};