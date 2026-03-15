class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int>diff;
        for(int i=0;i<n-1;i++){
            diff.push_back(nums[i+1] - nums[i]);
        }
        int m = diff.size();
        vector<int>pre(m,1),suf(m,1);
        for(int i=1;i<m;i++){
            if(diff[i] == diff[i-1]) pre[i]+=pre[i-1];
        }
        for(int i=m-2;i>=0;i--){
            if(diff[i] == diff[i+1]) suf[i]+=suf[i+1];
        }
        int ans = min(m,*max_element(pre.begin(),pre.end()) + 1);
        for(int i=0;i<m-1;i++){
            int lft = 1;
            int ryt  = 1;
            if(i != 0){
                int tar = diff[i-1];
                if(diff[i] + diff[i+1] == 2*tar){
                    lft =pre[i-1]+2;
                    if(i + 2 < m && diff[i+2] == tar) lft+=suf[i+2];
                }
            }
            if(i != m-2){
                int tar = diff[i+2];
                if(diff[i] + diff[i+1] == 2 * tar){
                    ryt = suf[i+2] + 2;
                    if(i > 0 && diff[i-1] == tar) ryt+=pre[i-1];
                }
            }
            ans = max({lft,ryt,ans});
        }
        return ans + 1;

    }
};