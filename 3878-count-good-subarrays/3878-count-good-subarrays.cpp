class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>lft(n,0),ryt(n,n-1),pre(31,-1),suff(31,n);
        for(int i=0;i<n;i++){
            for(int b=0;b<31;b++){
                if((nums[i] & (1<<b)) == 0){
                    lft[i] = max(lft[i],pre[b]+1);
                }else{
                    pre[b] = i;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<31;b++){
                if((nums[i] & (1<<b)) == 0){
                    ryt[i] = min(ryt[i],suff[b]-1);
                }else{
                    suff[b] = i;
                }
            }
        }
        long long ans = 0;
        unordered_map<int,int>last;
        for(int i=0;i<n;i++){
            int l = lft[i];
            if(last.count(nums[i])){
                l = max(l,last[nums[i]] + 1);
            }
            last[nums[i]] = i;
            int r = ryt[i];
            ans+= 1LL* (i - l +1) * (r - i + 1);
        }
        return ans;
    }
};