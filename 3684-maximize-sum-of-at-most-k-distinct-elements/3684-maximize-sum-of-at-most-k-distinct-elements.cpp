class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st;
        for(int a:nums)
            {
                st.insert(a);
            }
        vector<int>ans;
        int i = 0;
        // cout<<(int)st.size()-k<<endl;
        for(auto b:st)
        {
            if(i >= (int)st.size() - k) ans.push_back(b);
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};