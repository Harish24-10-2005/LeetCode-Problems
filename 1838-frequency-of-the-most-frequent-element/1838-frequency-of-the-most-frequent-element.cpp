class Solution {
public:
    int maxFrequency(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long total = 0;
        int ans = 1;
        int j = 0;
        for(int i=0;i<n;i++)
        {
            total += nums[i];
            while((long long)nums[i]*(i-j+1) - total > k)
            {
                total-=nums[j];
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};