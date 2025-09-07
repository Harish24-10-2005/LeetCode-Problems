class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        vector<int>ans;
        int summ = 0;
        for(int i=1;i<n;i++)
        {
            ans.push_back(i);
            summ+=i;
        }
        ans.push_back(-(summ));
        return ans;
    }
};