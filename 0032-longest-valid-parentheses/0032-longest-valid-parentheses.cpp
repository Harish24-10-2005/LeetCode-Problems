class Solution {
public:
    int longestValidParentheses(string s) {
        int maxx = 0;
        int n = s.size();
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxx = max(maxx, i - st.top());
                }
            }
        }
        return maxx;
    }
};