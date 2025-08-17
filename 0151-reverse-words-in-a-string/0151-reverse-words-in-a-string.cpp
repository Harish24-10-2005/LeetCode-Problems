class Solution {
public:
    string reverseWords(string s) {
        int pre = -1;
        int i = 0;
        while(i<s.size() && s[i] == ' ')
        {
            i++;
        }
        s.erase(0,i);
        i = s.size()-1;
        while(s[i] == ' ')
        {
            i--;
        }
        s.erase(i+1);
        i=1;
        while(i<s.size())
        {
            if(s[i] == ' '&& s[i-1] == ' ') s.erase(i,1);
            else i++;
        }
        if(i!=s.size()-1)s.erase(i);
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin()+pre+1,s.begin()+i);
                pre = i;
            }
        }
        reverse(s.begin()+pre+1,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};