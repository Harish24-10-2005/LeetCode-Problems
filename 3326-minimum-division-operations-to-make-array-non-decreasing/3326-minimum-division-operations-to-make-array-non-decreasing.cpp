class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i] <= nums[i+1]) continue;
            int cnt= 0;
            int sm = nums[i];
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i] % j == 0){
                    sm =j;
                    break;
                }
            }
            if(sm > nums[i+1]) return -1;
            nums[i] = sm;
            ans++;
        }
        return ans;
    }
};