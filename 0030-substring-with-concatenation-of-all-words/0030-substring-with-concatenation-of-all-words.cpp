class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mpp;
        vector<int>res;
        for(auto a:words)
        {
            mpp[a]++;
        }
        int n = s.size();
        int m = words[0].size();
        int wcnt = words.size();
        for(int st=0;st<m;st++)
        {
            int l = st;
            int cnt = 0;
            unordered_map<string,int>fre;
            for(int i=st;i+st<n;i+=m)
            {
                string temp = s.substr(i,m);
                cout<<temp<<endl;
                if(mpp.count(temp))
                {
                    fre[temp]++;
                    cnt++;
                    while(fre[temp] > mpp[temp])
                    {
                        string t = s.substr(l,m);
                        fre[t]--;
                        l+=m;
                        cnt--;
                    }
                    if(cnt == wcnt) res.push_back(l);
                }
                else
                {
                    fre.clear();
                    l = i + m;
                    cnt = 0;
                }
            }
        }
        return res;
    }
};