class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>has(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;

        has.erase(beginWord);
        q.push({beginWord,1});
        
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            string s =a.first;
            int l = a.second;
            if(s == endWord) return l;
            for(auto&ch:s)
            {
                char ori = ch;
                for(char i='a';i<='z';i++)
                {
                    ch = i;
                    if(has.find(s)!=has.end())
                    {
                        has.erase(s);
                        q.push({s,l+1});
                    }
                }
                ch = ori;
            }
        }
        return 0;
    }
};