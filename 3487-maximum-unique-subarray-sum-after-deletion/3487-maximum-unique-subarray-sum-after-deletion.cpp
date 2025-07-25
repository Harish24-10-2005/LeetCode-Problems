class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int ans  = INT_MIN;
        int temp  = 0;
        for(auto a:nums)
        {
            if(st.find(a) == st.end())
            {
                temp = max(temp+a,temp);
                // cout<<temp<<endl;
                ans = max(ans,temp);
            }
            st.insert(a);
        }
        
        if(ans == 0) return *max_element(nums.begin(),nums.end());
        return ans;
    }
};