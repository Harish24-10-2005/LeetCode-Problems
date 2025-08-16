class Solution {
private:
    bool rec(int st,int en,string s,unordered_set<string>&wordDict)
    {
        if(st == s.size()) return true;
        string temp = "";
        for(int i=st;i<en;i++)
        {
            temp+=s[i];
            // cout<<temp<<endl;
            if(wordDict.find(temp) != wordDict.end())
            {
                if(rec(i+1,en,s,wordDict)) return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>w;
        for(auto a:wordDict)
        {
            w.insert(a);
        }
        int n = s.size();
        return rec(0,n,s,w);
    }
};