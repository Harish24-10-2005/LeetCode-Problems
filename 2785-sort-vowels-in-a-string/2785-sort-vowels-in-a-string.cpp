class Solution {
public:
    string sortVowels(string s) {
        string t = "";
        string res = s;
        set<char>st{'a','e','i','o','u','A','E','I','O','U'};
        for(auto& a:res)
        {
            if(st.find(a)!= st.end())
            {
                t+=a;
                a='_';
            }
        }
        sort(t.begin(),t.end());
        int i =0 ;
        for(auto& a:res)
        {
            if(a == '_')
            {
                a = t[i];
                i++;
            }
        }
        return res;
    }
};