class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b)
        {
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        for(auto a:points)
        {
            cout<<a[1]<<endl;
        }
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
                        if(c >= points[j][1] && c< points[i][1])
                        {
                            f = false;
                            break;
                        }
                    }
                    if(f)
                    {
                        cout<<" 1st "<<points[i][0]<<" "<<points[i][1]<<" 2st "<<points[j][0]<<" "<<points[j][1]<<endl;
                        ans++;
                        col.push_back(points[j][1]);
                    }
                }
            }
        }
        return ans;
    }
};