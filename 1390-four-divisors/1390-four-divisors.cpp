class Solution {
private:
    pair<int,int> cnt(int n){
        int ans = 0;
        int summ = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                ans++;
                // cout<<i<<endl;
                summ+=i;
                if(i != n/i){
                    ans++;
                    // cout<<n/i<<endl;
                    summ+=(n/i);
                }
            }
        }
        return {ans,summ};
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i:nums){
            auto a = cnt(i);
            // cout<<a.first<<" "<<a.second<<"-------"<<endl;
            if(a.first == 4){
                ans+=a.second;
            }
        }
        return ans;
    }
};