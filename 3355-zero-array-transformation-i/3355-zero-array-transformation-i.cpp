class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>q(nums.size()+1,0);
        for(auto a:queries)
        {
            int st = a[0];
            int end = a[1];
            q[st]++;
            if(end + 1 < nums.size()) q[end+1]--;
        }
        int sub =0;
        for(int i=0;i<nums.size();i++)
        {
            sub+=q[i];
            if((nums[i]-sub)>0)
            {
                return false;
            }
        }
        return true;
    }
};