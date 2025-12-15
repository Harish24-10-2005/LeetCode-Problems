class Solution {
public:
    string reverseWords(string s) {
        vector<string>str;
        string t = "";
        for(auto a:s){
            if(a == ' '){
                str.push_back(t);
                t="";
            }
            else t+=a;
        }
        str.push_back(t);
        int v = 0;
        unordered_set<char>st{'a','e','i','o','u'};
        for(auto a:str[0]){
            if(st.count(a)) v++;
        }
        string res = str[0];
        if(str.size() > 1) res+=" ";
        for(int i=1;i<str.size();i++){
            int cnt = 0;
            for(auto a:str[i]){
                if(st.count(a)) cnt++;
            }
            if(cnt == v){
                reverse(str[i].begin(),str[i].end());
            }
            res+=str[i];
            if(i != str.size()-1) res+=" ";
        }
        return res;
    }
};