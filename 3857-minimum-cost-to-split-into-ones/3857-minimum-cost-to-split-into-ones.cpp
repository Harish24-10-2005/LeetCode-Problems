class Solution {
public:
    int minCost(int n) {
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            ans+=i;
        }
        return ans;
    }
};