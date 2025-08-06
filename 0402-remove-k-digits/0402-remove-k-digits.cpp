class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string s = "";
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && num[i]-'0' < st.top() && k>0)
            {
                st.pop();
                k--;
            }
            st.push(num[i]-'0');

        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            s+=to_string(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.size() && s[i] == '0') i++;
        s = s.substr(i);
        if(s == "")s="0"; 
        return s;
    }
};