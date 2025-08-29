class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string temp = "";
            for(int j = 0;j<min(s.size(),strs[0].size());j++)
            {
                if(s[j] == strs[i][j])
                {
                    temp+=s[j];
                }
                else break;
            }
            s = temp;
        }
        return s;
    }
};