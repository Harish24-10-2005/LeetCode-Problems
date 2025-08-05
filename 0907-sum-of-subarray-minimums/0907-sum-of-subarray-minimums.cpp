class Solution {
    long long MOD = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans  = 0;
        vector<int>p(n,-1),nex(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty()) p[i] = st.top();
            // else p[i] = i;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i] < arr[st.top()])
            {
                st.pop();
            }
            if(!st.empty()) nex[i] = st.top();
            // else nex[i] = i;
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            long long left = i - p[i];
            long long ryt = nex[i] - i;
            // if(p[i] == 0) left += 1;
            // if(nex[i] == n-1) ryt += 1;
            
            // cout<<"num ="<<arr[i]<<" left->"<<p[i]<<" ryt ->"<<nex[i]<<endl;
            // cout<<"num ="<<arr[i]<<" left->"<<left<<" ryt ->"<<ryt<<endl;
            // ans+=(left*(ryt*arr[i])%MOD)%MOD;
            long long t = ((left*ryt)%MOD*arr[i])%MOD;
            ans = (ans+t)%MOD;
        }
        return ans;
    }
};