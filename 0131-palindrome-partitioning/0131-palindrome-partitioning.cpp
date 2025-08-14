class Solution {
private:
    void rec(int idx,string s,vector<string>&temp,vector<vector<string>>&res)
    {
        if(idx == s.size()) res.push_back(temp);
        for(int i=idx;i<s.size();i++)
        {
            string t = s.substr(idx,i - idx +1); 
            string v = t;
            reverse(t.begin(),t.end());
            if(t == v)
            {
                temp.push_back(v);
                rec(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }   
public:
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>res;
        rec(0,s,temp,res);
        return res;
    }
};