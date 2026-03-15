class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int>mpp1,mpp2;
        for(int i:nums1) mpp1[i]++;
        for(int i:nums2) mpp2[i]++;
        int ans = 0;
        for(auto a:mpp1){
            int num = a.first;
            int c = a.second;
            int t = c + mpp2[num];
            if((c + mpp2[num]) %2 != 0) return -1;

            int diff = abs(c - mpp2[num]);
            ans += (diff/2);
        }
        for(auto a:mpp2){
            int num = a.first;
            int c = a.second;
            if(!mpp1.count(num)){
                int t = c + mpp1[num];
                if((c + mpp1[num]) %2 != 0) return -1;
                int diff = abs(c - mpp1[num]);
                ans += (diff/2);
            }
        }
        return ans/2;
    }
};