class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto a:nums)
        {
            st.insert(a);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i] - 1) == st.end())
            {
                int temp = 1;
                int x = nums[i];
                while(st.find(x+1) != st.end())
                {
                    x+=1;
                    temp++;
                }
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};