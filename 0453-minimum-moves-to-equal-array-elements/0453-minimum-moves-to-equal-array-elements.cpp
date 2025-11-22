class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int minn = *min_element(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++)
        {
            ans += (nums[i] - minn);
        }
        return ans;
    }
};