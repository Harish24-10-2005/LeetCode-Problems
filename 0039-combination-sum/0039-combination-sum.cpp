class Solution {
private:
    void rec(int i,int summ,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res)
    {
        if(i == nums.size())
        {
            if(summ == 0) res.push_back(temp);
            return;
        }
        if(summ-nums[i] >=0)
        {
            temp.push_back(nums[i]);
            rec(i,summ-nums[i],nums,temp,res);
            temp.pop_back();
        }
        rec(i+1,summ,nums,temp,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        rec(0,target,candidates,temp,res);
        return res;
    }
};