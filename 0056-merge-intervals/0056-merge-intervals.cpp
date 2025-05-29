class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int>temp = intervals[0];
        for(auto it: intervals)
        {
            if(it[0]<=temp[1])
            {
                temp[1]=max(temp[1],it[1]);
            }
        
            else{
                res.push_back(temp);
                temp = it;
            }
        }
        res.push_back(temp);
        return res;
    }
};