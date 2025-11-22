class Solution {
private:
    string s,p;
    bool rec(int i,int j)
    {
        if(i == s.size() && j >= p.size()) return true;
        if(i < s.size() && j >= p.size()) return false;
        if(i == s.size())
        {
            if(p[j] == '*' ||(j+1 <p.size() && p[j+1] =='*'))return rec(i,j+1);
        }
        cout<<i<<" "<<j<<endl;
        bool res = false;
        if((p[j]>='a' && p[j]<='z') || p[j] == '.')
        {
            cout<<"a"<<endl;
            if(s[i] == p[j] || p[j] == '.')
            {
                res = rec(i+1,j+1);
            }
            if(j+1 < p.size() && p[j+1] == '*')
            {
                res = rec(i,j+1);
            }
        }
        else
        {
            cout<<"*"<<endl;
            if(p[j-1] == s[i] || p[j-1] =='.')
            {
                res = rec(i+1,j+1);
                res |= rec(i+1,j);
            } 
            res |= rec(i,j+1);
        }
        return res;
    }
public:
    bool isMatch(string st, string pt) {
        p = pt;
        s = st;
        return rec(0,0);
    }
};