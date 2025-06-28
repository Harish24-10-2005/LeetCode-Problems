class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>vwi;
        for(int i=0;i<nums.size();i++)
        {
            vwi.push_back({nums[i],i});
        }
        sort(vwi.begin(),vwi.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });
        vector<int>ind,res;
        int t = k;
        for(auto a:vwi)
        {
            if(t == 0) break;
            ind.push_back(a.second);
            t--;
        }
        sort(ind.begin(),ind.end());
        for(int i:ind)
        {
            res.push_back(nums[i]);
        }
        return res;
    }
};