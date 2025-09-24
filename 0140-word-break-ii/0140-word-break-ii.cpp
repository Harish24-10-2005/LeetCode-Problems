class Solution {
private:
    void rec(int i,string s,string ans,string temp,vector<string>&res,unordered_set<string>&st)
    {
        if(i == s.size())
        {
            if(st.find(temp) != st.end())
            {
                ans+=temp;
                res.push_back(ans);
            }
            return;
        }
        cout<<temp<<endl;
        if(st.find(temp) != st.end())
        {
            string t="";
            string ta = ans+temp;
            rec(i+1,s,ta+" ",t+s[i],res,st);

        }
        rec(i+1,s,ans,temp+s[i],res,st);
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto a:wordDict)
        {
            st.insert(a);
        }
        vector<string>res;
        rec(0,s,"","",res,st);
        return res;
    }
};