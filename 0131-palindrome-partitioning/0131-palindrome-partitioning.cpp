class Solution {
private:
    bool ispal(string s)
    {
        string t = s;
        reverse(s.begin(),s.end());
        return s == t;
    }
    void rec(int node,string &s,vector<vector<string>>&res,vector<string>&temp)
    {
        if(node == s.size())
        {
            if(!temp.empty())
            {
                res.push_back(temp);
            }
            return;
        }
        string t = "";
        for(int i=node;i<s.size();i++)
        {
            t+=s[i]; 
            if(ispal(t))
            {
                temp.push_back(t);
                rec(i+1,s,res,temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        rec(0,s,res,temp);
        return res;
    }
};