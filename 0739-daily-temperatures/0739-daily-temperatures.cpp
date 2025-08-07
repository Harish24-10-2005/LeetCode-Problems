class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n,-1);
        stack<int>st; 
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[i]>=temperatures[st.top()])
            {
                st.pop();
            }
            if(!st.empty()) res[i] = st.top();
            else res[i] = i;
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            res[i] = res[i] - i;
        }
        return res;
    }
};