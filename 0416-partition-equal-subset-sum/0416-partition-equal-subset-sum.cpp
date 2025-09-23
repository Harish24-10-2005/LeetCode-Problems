class Solution {
private:
    bool rec(int i,int tar,vector<int>&nums)
    {
        if(tar == 0) return true;
        if( i== nums.size()) return false;
        bool t = false;
        if(tar - nums[i] >=0)
        {
            t = rec(i+1,tar-nums[i],nums);
        }
        bool nt = rec(i+1,tar,nums);
        return t || nt;
    }
public:
    bool canPartition(vector<int>& nums) {
        int summ = accumulate(nums.begin(),nums.end(),0);
        int tar = summ/2;
        if(summ%2 != 0) return false;
        return rec(0,tar,nums);
        
    }
};