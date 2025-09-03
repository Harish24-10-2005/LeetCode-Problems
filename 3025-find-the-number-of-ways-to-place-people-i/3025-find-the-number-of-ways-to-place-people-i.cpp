class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b)
        {
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int ans = 0;
        vector<int>col;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(points[i][1] >= points[j][1])
                {
                    bool f = true;
                    for(int c:col)
                    {
                        if(!(points[c][1] == points[i][1] && points[c][0] == points[i][0]) && !(points[c][1] == points[j][1] && points[c][0] == points[j][0]) && (points[c][1] >= points[j][1] && points[c][1] <= points[i][1]) && (points[c][0] <= points[j][0] && points[c][0] >= points[i][0]))
                        {
                            f = false;
                            break;
                        }
                    }
                    if(f)
                    {
                        ans++;
                        col.push_back(j);
                    }
                }
            }
        }
        return ans;
    }
};