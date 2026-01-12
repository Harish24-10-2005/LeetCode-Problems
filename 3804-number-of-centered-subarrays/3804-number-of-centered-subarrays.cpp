class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            int summ = 0;
            for(int j=i;j<n;j++){
                summ+=nums[j];
                st.insert(nums[j]);
                if(st.count(summ)) ans++;
            }
        }
        return ans;
    }
};