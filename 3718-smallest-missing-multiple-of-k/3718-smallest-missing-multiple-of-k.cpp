class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st(nums.begin(),nums.end());
        int temp = k;
        for(auto a:st)
        {
            if(a%k!= 0) continue;
            if(temp != a) return temp;
            temp+=k;
        }
        return temp;
    }
};