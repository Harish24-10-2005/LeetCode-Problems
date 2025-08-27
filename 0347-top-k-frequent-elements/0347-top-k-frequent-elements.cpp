class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        vector<int>ans;
        vector<vector<int>>t(n+1);
        for(auto a:mpp)
        {
            t[a.second].push_back(a.first);
        }
        int i = n;
        while(i>= 0 && k > 0)
        {
            if(t[i].size() <= k)
            {
                ans.insert(ans.end(),t[i].begin(),t[i].end());
                k-=t[i].size();
            }
            else
            {
                ans.insert(ans.end(),t[i].begin(),t[i].begin()+k);
                k = 0;
            }
            i--;
        }
        return ans;
    }
};