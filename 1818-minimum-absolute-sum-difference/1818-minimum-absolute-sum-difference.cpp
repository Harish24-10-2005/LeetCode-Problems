class Solution {
private:
    int small(vector<int>&nums,int tar){
        int l = 0;
        int ans = -1;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(nums[mid] <= tar){
                ans = mid;
                l = mid+1;
            }else{
                r = mid -1;
            }
        }
        return ans;
    }
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int MOD = 1e9 + 7;
        long long summ = 0;
        for(int i=0;i<n;i++){
            summ+=abs(nums1[i] - nums2[i]) ;
        }
        vector<int>nums = nums1;
        sort(nums.begin(),nums.end());
        int ans  = INT_MIN;
        // cout<<summ<<endl;
        for(int i=0;i<n;i++){
            int temp = abs(nums1[i] - nums2[i]);
            auto it = lower_bound(nums.begin(),nums.end(),nums2[i]);

            if(it != nums.end()) ans = max(ans,temp - abs(*it - nums2[i]));
            int sm = small(nums,nums2[i]);
            if(!(sm <= n-1 && sm >= 0)) continue;
            // cout<<nums2[i]<<" "<<nums[sm]<<endl;
            ans = max(ans,(temp - abs(nums[sm] - nums2[i])));
        }
        return (summ - ans) % MOD;
    }
};