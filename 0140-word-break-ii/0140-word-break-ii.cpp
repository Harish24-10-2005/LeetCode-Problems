class Solution {
    vector<string>res;
    unordered_set<string>has;
    int n;
private:
    void rec(int i,string s,string temp,string ans)
    {
        if(i == n)
        {
            if(has.find(temp) != has.end())
            {
                ans += temp;
                res.push_back(ans);
            }
            return;
        }
        cout<<temp<<endl;
        if(has.find(temp) != has.end())
        {
            string t = "";
            t += s[i];
            rec(i+1,s,t,ans + temp + " ");
        }
        rec(i+1,s,temp + s[i],ans);
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(auto a:wordDict)
        {
            has.insert(a);
        }
        rec(0,s,"","");
        return res;
    }
};