class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int num = 0;
        int sign = 1;
        stack<int>st;
        st.push(sign);
        for(auto a:s)
        {
            if(isdigit(a))
            {
                num = num * 10 + (a - '0');
            }
            else if(a == '(')
            {
                st.push(sign);
            }
            else if(a == ')')
            {
                st.pop();
            }
            else if(a == '+' || a == '-')
            {
                ans += sign * num;
                sign = (a == '+' ? 1:-1) * st.top();
                num = 0;
            }
        }
            return ans + sign* num;
    }
};