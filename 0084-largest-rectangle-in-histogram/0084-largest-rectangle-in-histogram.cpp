class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pre(n,-1);
        vector<int>suf(n,n);

        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty()) pre[i] = st.top();
            st.push(i);
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if(!st.empty()) suf[i] = st.top();
            st.push(i);
        }
        cout<<endl;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            cout<<suf[i]<<" ";
            int lft= i - pre[i];
            int ryt = suf[i] - i;
            ans = max(ans,(lft + ryt - 1)*heights[i]);
        }
        return ans;

    }
};