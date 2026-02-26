class Solution {
private:
    int n;
    vector<vector<int>>dp;
    // unordered_map<string,int>dp;
    int rec(int i,int num,vector<int>&nums){
        if(i == n) return nums[num];
        // cout<<num<<endl;
        if(i == n-1) return max(nums[num],nums[i]);
        if(dp[i][num] != -1) return dp[i][num];
        // vector<int>temp{nums[num],nums[i],nums[i+1]};
        // sort(temp.begin(),temp.end());

        // int t1 = temp[0];
        // int t2 = temp[1];
        // int t3 = temp[2];
        return dp[i][num] = min({
            max(nums[num],nums[i]) + rec(i+2,i+1,nums),
            max(nums[num],nums[i+1]) + rec(i+2,i,nums),
            max(nums[i],nums[i+1]) + rec(i+2,num,nums)
        });
    }
public:
    int minCost(vector<int>& nums) {
        n = nums.size();
        dp.assign(n,vector<int>(n,-1));
        return rec(1,0,nums);
    }
};