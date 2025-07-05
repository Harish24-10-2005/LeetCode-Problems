class Solution {
    bool is_pal(string s,int st,int end)
    {
        int i= st;
        int j =end;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void rec(int i,string s,vector<string>&temp,vector<vector<string>>&res)
    {
        if(i == s.size())
        {
            res.push_back(temp);
            return;
        }
        string summa ;
        for(int j=i;j<s.size();j++)
        {
            summa+=s[j];
            if(is_pal(s,i,j))
            {
                temp.push_back(summa);
                rec(j+1,s,temp,res);
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        rec(0,s,temp,res);
        return res;
    }
};