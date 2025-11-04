class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,INT_MIN);
        vector<int>nex(n,INT_MIN);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top() >= nums[i])
            {
                st.pop();
            }
            if(!st.empty()) nex[i] = st.top();
            st.push(nums[i]);
        }
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top() >= nums[i])
            {
                st.pop();
            }
            if(!st.empty()) pre[i] = st.top();
            st.push(nums[i]);
        }
        // cout<<s.size()<<endl;
        for(int i=0;i<n;i++)
        {
            if((pre[i]!= INT_MIN && nex[i]!=INT_MIN) && nex[i] > pre[i]) return true;
        }
        return false;
    }
};