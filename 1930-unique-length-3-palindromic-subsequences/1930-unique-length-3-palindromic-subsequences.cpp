class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        vector<pair<int,int>>temp(26,pair<int,int>{-1,-1});
        for(int i=0;i<n;i++)
        {
            char ch = s[i]-'a';
            if(temp[ch].first == -1)
            {
                temp[ch].first = i;
            }
            else
            {
                temp[ch].second = i;
            }
        }
        for(int i=0;i<26;i++)
        {
            int st = temp[i].first;
            int end = temp[i].second;
            unordered_set<char>has;
            if(st != -1 && end != -1)
            {
                for(int j=st+1;j<end;j++)
                {
                    has.insert(s[j]);
                }
            }
            ans+=has.size();
        }
        return ans;
    }
};