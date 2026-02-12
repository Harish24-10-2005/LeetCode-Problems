class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans1 = 0,ans2 = 0;
        int l1= 0,l2 = 0;
        int t1 = 0,t2 = 0;
        for(int i=0;i<n;i++){
            t1+=nums[i];
            t2+=nums[i];
            while(l2 <= i && t2 > goal-1){
                t2-=nums[l2];
                l2++;
            }
            while(l1 <= i && t1 > goal){
                t1-=nums[l1];
                l1++;
            }
            ans1 += i - l1 + 1;
            ans2 += i - l2 + 1;
        }
        return ans1 - ans2;
    }
};