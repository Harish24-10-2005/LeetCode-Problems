class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        for(int i=2;i<n;i++)
        {
            ans = max(ans, abs(stones[i]-stones[i-2]));
        }
        ans = max(ans,abs(stones[1]-stones[0]));
        ans = max(ans,abs(stones[n-2] - stones[n-1]));
        return ans;
    }
};