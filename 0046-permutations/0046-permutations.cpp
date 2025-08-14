class Solution {
private:
    void pre(int i,vector<int>&temp,vector<int>&nums,vector<int>&vis,vector<vector<int>>&res)
    {
        if(i == nums.size())
        {
            res.push_back(temp);
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(vis[j]!=1)
            {
                vis[j] = 1;
                temp.push_back(nums[j]);
                pre(i+1,temp,nums,vis,res);
                temp.pop_back();
                vis[j] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        vector<int>vis(nums.size(),0);
        pre(0,temp,nums,vis,res);
        return res;
    }
};