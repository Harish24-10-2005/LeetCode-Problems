class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i=1;i<n;i++)
        {
            string s = "";
            int cnt = 1;
            s+=res[0];
            for(int i=1;i<res.size();i++)
            {
                if(s[s.size()-1] != res[i])
                {
                    s+=to_string(cnt);
                    cnt = 1;
                    swap(s[s.size()-2],s[s.size()-1]);
                    s+=res[i];
                }
                else cnt++;
            }
            if(s[s.size()-1] == res[res.size()-1])
            {
                s+=to_string(cnt);
                swap(s[s.size()-2],s[s.size()-1]);
            }
            cout<<s<<endl;
            res = s;
        }
        return res;
    }
};