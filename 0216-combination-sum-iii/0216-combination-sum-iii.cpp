class Solution {
    int m;
private:
    void rec(int idx,int summ,int k,vector<int>&temp,vector<int>&nums,vector<vector<int>>&res)
    {
        if(temp.size() > k) return;
        if(summ == 0)
        {
            if(temp.size() == k)res.push_back(temp);
            return;
        } 
        for(int i = idx;i<nums.size();i++)
        {
            if((summ-nums[i] < 0) ||(i!=idx && nums[i] == nums[i-1]) )continue;
            temp.push_back(nums[i]);
            rec(i+1,summ-nums[i],k,temp,nums,res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        m = n;
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<int>temp;
        vector<vector<int>>res;
        rec(0,n,k,temp,nums,res);
        return res;
    }
};