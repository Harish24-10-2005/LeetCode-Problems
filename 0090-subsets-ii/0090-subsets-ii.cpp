class Solution {
private:
    void rec(int i,vector<int>&t,vector<int>&nums,vector<vector<int>>&res)
    {
        if(i == nums.size())
        {
            res.push_back(t);
            return;
        }
        int j = i+1;
        while(j<nums.size() && nums[i] == nums[j])
        {
            j++;
        }
        t.push_back(nums[i]);
        rec(j,t,nums,res);
        t.pop_back();
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>t;
        rec(0,t,nums,res);
        return res;
    }
};