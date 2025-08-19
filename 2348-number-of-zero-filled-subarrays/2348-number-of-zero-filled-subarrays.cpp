class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;)
        {
            int j = i+1;
            if(nums[i] == 0)
            {
                int temp = 1;
                while(j<n && nums[j]==0)
                {
                    temp++;
                    j++;
                }
                ans.push_back(temp);
                i = j+1;
            }
            else i++;
        }
        long long a = 0;
        // bool f = 0;
        for(int i:ans)
        {
            a+=(((long long)i*(i+1))/2);
        }
        return a;
    }
};