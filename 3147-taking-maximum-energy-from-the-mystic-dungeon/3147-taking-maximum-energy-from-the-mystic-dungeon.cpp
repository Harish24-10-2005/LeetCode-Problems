class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>ans(n);
        for(int i = n-1;i>=n-k;i--)
        {
            ans[i] = energy[i];
        }
        for(int i = n-k-1;i>=0;i--)
        {
            ans[i] = energy[i] + ans[i+k];
        }
        // for(auto a:ans)
        // {
        //     cout<<a<<" ";
        // }
        return *max_element(ans.begin(),ans.end());
    }
};