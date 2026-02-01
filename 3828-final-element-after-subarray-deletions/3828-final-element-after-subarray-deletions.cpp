class Solution {
public:
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        // int st = 0;
        // int end = n-1;
        // // while((end - st + 1) > 1){
        //     int minn = 0;
        //     int maxx = 0;
        //     for(int i=0;i<n;i++){
        //         if(nums[i] < nums[minn]) minn = i;
        //         if(nums[i] > nums[maxx]) maxx = i;
        //     }
        //     if(nums[minn] == nums[maxx])return nums[minn];

        //     if(nums[st] > nums[end]) end = minn-1;
        //     else st = end;

        //     if(end - st + 1 == 1) return nums[st];


        //     for(int i=st;i<=end;i++){
        //         if(nums[i] > nums[maxx]) maxx = i;
        //     }
        //     if(nums[st] > nums[end]) st = maxx+1;
        //     else end = maxx-1;
        // // }
        // return nums[st];
        return max(nums[0],nums[n-1]);
    }
};