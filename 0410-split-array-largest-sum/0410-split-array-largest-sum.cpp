class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int temp_k=1;
            int temp_max = 0;
            for(int i = 0;i<nums.size();i++)
            {
                if(temp_max+nums[i]<=mid)
                {
                    temp_max+=nums[i];
                }
                else
                {
                    temp_k++;
                    temp_max = nums[i];
                }
            }
            if(temp_k<=k)
            {
                r = mid -1;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};