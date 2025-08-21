class Solution {
private:
    int find(vector<int>&m)
    {
        int n = m.size();
        vector<int>p(n,n);
        vector<int>s(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && m[st.top()] > m[i])
            {
                st.pop();
            }
            if(!st.empty()) p[i] = st.top();
            st.push(i);
            cout<<p[i]<<" ";
        }
        cout<<endl;
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && m[st.top()] >= m[i])
            {
                st.pop();
            }
            if(!st.empty()) s[i] = st.top();
            st.push(i);
            cout<<s[i]<<" ";
        }
        cout<<endl;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(m[i] != 0)
            {
                int lft = p[i] - i;
                int ryt = i - s[i];
                // cout<<p[i]<<"  "<<s[i]<<" "<<(p[i] - s[i] - 1)<<endl;
                int t = lft * ryt * m[i];
                ans+=t;
            }
        }
        return ans;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int>h(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 1)
                {
                    h[j]+=1;
                }
                else h[j] = 0;
                // cout<<h[j]<<" ";
            }
            ans+=find(h);
            // cout<<endl;
        }
        return ans;
    }
};