class Solution {
private:
    void rec(int idx,int target,vector<int>&t,vector<int>&nums,vector<vector<int>>&res)
    {
        if(target == 0) res.push_back(t);
        for(int i=idx;i<nums.size();i++)
        {
            if((target - nums[i] <0) || (i>idx && nums[i] == nums[i-1])) continue;
            t.push_back(nums[i]);
            rec(i+1,target-nums[i],t,nums,res);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        rec(0,target,temp,candidates,res);
        return res;
    }
};