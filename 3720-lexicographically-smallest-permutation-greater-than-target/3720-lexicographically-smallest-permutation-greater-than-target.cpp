class Solution {
    int n;
    vector<int>cnt;
    string ans= "";
private:
    bool rec(int idx,string& temp,string& s,string& t,bool perfect)
    {
        if(!ans.empty())return true;
        if(idx == n) 
        {
            if (!perfect) {
                ans = temp;
                return true;
            }
            return false;
        }
        for(int i=0;i<26;i++)
        {
            if(cnt[i] == 0) continue;

            char c = (i + 'a');
            if(perfect && (c < t[idx])) continue;

            bool Nextperfect = perfect && (c == t[idx]);

            temp+=c;
            cnt[i]--;


            if(rec(idx+1,temp,s,t,Nextperfect)) return true;


            cnt[i]++;
            temp.pop_back();
        }
        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        n = s.size();
        cnt.assign(26,0);
        for(auto a:s) cnt[a - 'a']++;
        string res;
        rec(0,res,s,target,true);
        return ans;
    }
};