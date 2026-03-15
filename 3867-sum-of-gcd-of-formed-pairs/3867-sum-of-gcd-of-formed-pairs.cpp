class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>pre(n,0);
        long long maxx = nums[0];
        for(int i=0;i<n;i++){
            maxx = max(maxx,(long long)nums[i]);
            pre[i] = __gcd((long long)nums[i],maxx);
        }
        sort(pre.begin(),pre.end());
        long long ans = 0;
        int i=0;
        int j=n-1;
        while(i<j){
            // cout<<__gcd(pre[i],pre[j])<<endl;
            ans+= __gcd(pre[i],pre[j]);
            i++;
            j--;
        }
        return ans;
    }
};