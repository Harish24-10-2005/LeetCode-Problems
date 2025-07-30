class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =nums.size();
        int ans = INT_MIN;
        int temp = 1;
        for(int i=0;i<n;i++)
        {
            temp = max(temp*nums[i],nums[i]);
            ans = max(ans,temp);
        }
        return ans;
    }
};