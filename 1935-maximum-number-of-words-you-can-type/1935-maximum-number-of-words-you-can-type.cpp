class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>arr;
        string s = "";
        bool c = false;
        bool p = false;
        for(int i=0;i<text.size();i++)
        {
            if(text[i] == ' ') 
            {
                arr.push_back(s);
                s = "";
                continue;
            }   
            s+=text[i];
        }
        arr.push_back(s);
        for(int i=0;i<brokenLetters.size();i++)
        {
            for(auto& a:arr)
            {
                for(auto b:a)
                {
                    if(b == brokenLetters[i])
                    {
                        a = "";
                        break;
                    }
                }
            }
        }
        int ans = 0;
        for(auto a:arr)
        {
            if(a != "")ans++;
        }
        return ans;
    }
};