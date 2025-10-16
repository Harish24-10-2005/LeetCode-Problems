class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        set<int>st;
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int t = abs(nums[i]) % value;
            if(nums[i] < 0 && t != 0)
            {
                t = (-t) + value;
            }
            while(st.find(t) != st.end())
            {
                t+=value;
            }
            st.insert(t);
        }
        int temp = 0;
        for(auto a:st)
        {
            // cout<<a<<" ";
            if(a != temp)
            {
                return temp;
            }
            temp++;
        }
        return temp;
    }
};