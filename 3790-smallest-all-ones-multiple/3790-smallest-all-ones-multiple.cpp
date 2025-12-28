class Solution {
public:
    int minAllOneMultiple(int k) {
        int ans = 1;
        long long res = 1;
        // res = (res + k) % k;
        if(k == 1) return 1;
        if(k%2 == 0 || k %5 == 0 ) return -1; 
        while(res%k){
            res= (res * 10) + 1;
            // cout<<res<<endl;
            res = (res + k) % k;
            ans++;
        }
        return ans;
    }
};