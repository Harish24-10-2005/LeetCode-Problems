class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(),i.end());
        int f = i[0][0];
        int s = i[0][1];

        vector<vector<int>>ans;

        for(int j=1;j<i.size();j++)
        {
            int tf = i[j][0];
            int ts = i[j][1];
            if(tf > s)
            {
                ans.push_back({f,s});
                f = tf;
                s = ts;
            }
            else
            {
                s = max(s,ts);
            }
        }
        ans.push_back({f,s});
        return ans;
    }
};