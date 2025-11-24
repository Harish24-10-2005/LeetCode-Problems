class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int temp = 0;
        int n = nums.size();
        vector<bool>res(n,false);
        for(int i=0;i<n;i++)
        {
            temp = temp << 1;
            temp += nums[i];
            if(temp % 5 == 0) res[i] = true;
            temp %= 5;
        }
        return res;
    }
};