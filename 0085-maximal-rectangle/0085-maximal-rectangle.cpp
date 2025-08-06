class Solution {
private:
    int findmax(vector<int>&h)
    {
        int n = h.size();
        vector<int>p(n,-1);
        vector<int>s(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && h[i]<=h[st.top()])
            {
                st.pop();
            }
            if(!st.empty()) p[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && h[i]<=h[st.top()])
            {
                st.pop();
            }
            if(!st.empty()) s[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int left = i-p[i]-1;
            // cout<<"left->"<<left
            int ryt = s[i] - i;
            int t = (left + ryt) * h[i];
            ans = max(ans,t);
        }
        cout<<ans<<endl;
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m = matrix[0].size();
        int res= 0;
        vector<int>h(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] - '0' == 0)
                {
                    h[j] = 0;
                }
                else h[j]+=1;
            }
            for(auto a:h)cout<<a<<" ";
            cout<<endl;
            res = max(res,findmax(h));
        }   
        return res;
    }
};