class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int gap = 0;
        bool f = true;
        for(int i=0;i<n;i++)
        {
            if((f && nums[i] == 1))
            {
                gap = 0;
                f = false;
                continue;
            }
            else if(nums[i] == 1)
            {
                if(gap < k) return false;
                gap = 0;
            }
            else
            {
                gap++;
            }
            cout<<gap<<endl;
        }
        return true;
    }
};