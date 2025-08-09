class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];
        int cnt = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i] == temp) cnt++;
            else cnt--;
            if(cnt == 0){
                temp = nums[i];
                cnt = 1;
            }
        }
        // cnt  = 0;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]  == temp) cnt++;
        // }
        return temp;
    }
};