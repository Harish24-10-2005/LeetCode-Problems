class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int summ = accumulate(nums.begin(),nums.end(),0);
        return summ%k;
    }
};