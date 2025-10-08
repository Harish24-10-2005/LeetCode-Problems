class Solution {
    int m;
    void rec(int o,int c,string s,vector<string>&res)
    {
        if(c == m && o == m)
        {
            res.push_back(s);
            return;
        }
        if(o < m) rec(o+1,c,s+"(",res);
        if(o > c)
        {
            rec(o,c+1,s+")",res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        m = n;
        vector<string>res;
        rec(0,0,"",res);
        return res;
    }
};