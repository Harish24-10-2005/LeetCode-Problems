class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<=n-2*k;i++)
        {
            bool f = false;
            for(int j=1;j<k;j++)
            {
                if(nums[i+j-1] >= nums[i+j])
                {
                    f = true;
                    break;
                }
            }
            if(!f)
            {
                for(int j=k+1;j<2*k;j++)
                {
                    if(nums[i+j-1] >= nums[i+j])
                    {
                        f = true;
                        break;
                    }
                }
            } 
            // cout<<"JIJII"<<endl;
            if(!f) return true;
        }
        return false;
    }
};