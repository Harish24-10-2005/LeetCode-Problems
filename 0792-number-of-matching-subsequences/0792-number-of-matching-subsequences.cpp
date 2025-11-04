class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        vector<vector<pair<int,int>>>buc(26);
        for(int i=0;i<words.size();i++)
        {
            buc[words[i][0] - 'a'].push_back({i,0});
        }

        for(int i=0;i<s.size();i++)
        {
            if(buc[s[i]-'a'].size() > 0)
            {
                vector<pair<int,int>>temp = buc[s[i]-'a'];
                buc[s[i]-'a'] = {};
                for(auto a:temp)
                {
                    int w = a.first;
                    int c = a.second;
                    if(c+1 < words[w].size())
                    {
                        buc[words[w][c+1] - 'a'].push_back({w,c+1});
                    }
                    else
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};