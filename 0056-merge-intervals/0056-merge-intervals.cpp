class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int f = intervals[0][0];
        int s = intervals[0][1];
        for(int i=1;i<n;i++)
        {
            int tf = intervals[i][0];
            int ts = intervals[i][1];
            if(tf <= s) 
            {
                s = max(s,ts);
            }
            else{
                ans.push_back({f,s});
                f = tf;
                s = ts;
            }
        }
        if(intervals[n-1][0] <= s)
        {
            ans.push_back({f,intervals[n-1][1]});
        }
        else
        {
            ans.push_back({intervals[n-1][0],intervals[n-1][1]});
        }
        return ans;
    }
};