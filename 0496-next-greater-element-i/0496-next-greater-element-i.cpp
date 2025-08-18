class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums2.size();
        vector<int>res(n,-1);
        vector<int>ans(nums1.size());
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>st.top())
            {
                st.pop();
            }
            if(!st.empty()) res[i] = st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            int a = -1;
            for(int j=0;j<n;j++)
            {
                if(nums1[i] == nums2[j])
                {
                    a = res[j];
                    break;
                }
            }
            ans[i] = a;
        }
        return ans;
    }
};