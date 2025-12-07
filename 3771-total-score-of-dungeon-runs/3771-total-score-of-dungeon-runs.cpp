class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long>com(n,0);
        com[0] = damage[0];
        for(int i=1;i<n;i++)
        {
            com[i] = com[i-1] + (long long)damage[i];
        }        
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            long long nneed = requirement[i] + com[i] - hp;
            auto end = com.begin() + i; 
            auto st = lower_bound(com.begin(),com.begin() + i + 1,nneed);
            if((end - st) >= 0)ans+=(long long)(end - st);
            if (nneed <= 0) ans++;
        }
        return ans;
    }
};