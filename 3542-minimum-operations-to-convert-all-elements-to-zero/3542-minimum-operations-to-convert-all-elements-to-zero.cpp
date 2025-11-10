class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        vector<int>temp(n,n);
        stack<int>st;
        int ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if(!st.empty()) temp[i] = st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            if((nums[i] == 0) || (mpp.count(nums[i]) && mpp[nums[i]] >= i))
            {
                continue;
            }
            ans++;
            // cout<<nums[i]<<"   "<<temp[i]<<endl;
            mpp[nums[i]] = temp[i]-1;
        }
        return ans;
    }
};