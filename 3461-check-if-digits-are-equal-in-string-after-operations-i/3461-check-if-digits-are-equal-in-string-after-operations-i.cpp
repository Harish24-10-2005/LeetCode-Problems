class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        while(s.size()>2)
        {
            int i=0;
            int j=1;
            string temp ="";
            while(j<s.size())
            {
                // cout<<s[i]<<"-----------------------";
                int first = s[i] - '0';
                int sec = s[j] - '0';
                int res = (first + sec)%10;
                temp += to_string(res);
                // cout<<temp;
                i++;
                j++;
            }
            s = temp;
            cout<<s<<endl;
            
        }
        if(s[0]==s[1])
        {
            return true;
        }
        return false;
    }
};