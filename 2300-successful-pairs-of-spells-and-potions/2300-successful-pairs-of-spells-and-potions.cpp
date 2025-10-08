class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int>ans(n);
        sort(potions.begin(),potions.end());
        int m = potions.size();
        for(int i=0;i<n;i++)
        {
            long long a = (success+spells[i] -1)/spells[i];
            int idx = lower_bound(potions.begin(),potions.end(),a) - potions.begin();
            

            ans[i] = m-idx;
        }
        return ans;
    }
};