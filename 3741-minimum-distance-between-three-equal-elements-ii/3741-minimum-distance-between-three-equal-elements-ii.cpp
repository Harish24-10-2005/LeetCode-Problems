class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,set<int>>mpp;
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mpp.count(nums[i]))
            {
                if(mpp[nums[i]].size() == 3)
                {
                    mpp[nums[i]].erase(mpp[nums[i]].begin());
                }
                if(mpp[nums[i]].size() == 2)
                {
                    int k = *mpp[nums[i]].begin();
                    auto it = mpp[nums[i]].begin();
                    it++;
                    int j = *it;
                    ans = min(ans,(abs(k - j) + abs(j - i) + abs(i - k)));
                }
            }
            mpp[nums[i]].insert(i);
        }
        return ans == INT_MAX ? -1 :ans;
    }
};