class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();
        int n = len/2;
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=1;i<len;i++){
            if(nums[i] == nums[i-1]) cnt++;
            else cnt =0;
            if(cnt == n-1){
                return nums[i];
            }
        }
        return -1;
    }
};