class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>left(n,vector<int>(2,1)),right(n,vector<int>(2,1));
        int maxx = 1;

        for(int i=1;i<n;i++){
            if(nums[i] < nums[i-1]){
                left[i][0] += left[i-1][1];
            }else if(nums[i] > nums[i-1]){
                left[i][1] += left[i-1][0];
            }
            maxx = max({maxx,left[i][1],left[i][0]});
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                right[i][0] +=right[i+1][1];
            }else if(nums[i] > nums[i+1]){
                right[i][1] +=right[i+1][0];
            }
            maxx = max({maxx,right[i][1],right[i][0]});
        }
        for(int i =1;i<n-1;i++){
            if(nums[i-1] < nums[i+1]){
                maxx = max(maxx,left[i-1][0] + right[i+1][1]);
            }
            else if(nums[i-1] > nums[i+1]){
                maxx = max(maxx,left[i-1][1] + right[i+1][0]);
            }
        }

        return maxx;
    }
};