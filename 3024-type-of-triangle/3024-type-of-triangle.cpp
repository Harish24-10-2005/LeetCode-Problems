class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int>st;
        int summ = 0;
        for(int i:nums)
        {
            summ+=i;
            st.insert(i);
        }
        int maxx = max(nums[0],max(nums[1],nums[2]));
        int t_summ = summ - maxx;
        if(t_summ <= maxx) return "none";
        if(st.size() == 1) return "equilateral";
        if(st.size() == 2) return "isosceles";
        else return "scalene";
    }
};