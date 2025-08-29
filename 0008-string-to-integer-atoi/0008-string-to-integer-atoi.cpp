class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int t = 1;
        int i=0;
        for(i;i<s.size();i++)
        {
            if(s[i] == ' ')continue;
            else break;
        }
        // cout<<s[i]<<endl;
        if(s[i] == '-' || s[i] == '+') 
        {
            if(s[i] == '-') t=-1;
            i++;
        }
        for(i;i<s.size();i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                res*=10;
                res+=(s[i]-'0');
                if(res> INT_MAX) return t == -1 ? INT_MIN : INT_MAX;
                if(res<INT_MIN) return t == -1 ? INT_MAX : INT_MIN;
            }
            else break;
        }
        return t*res;
    }
};