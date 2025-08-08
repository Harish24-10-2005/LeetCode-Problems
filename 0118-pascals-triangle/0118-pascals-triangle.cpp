class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows);
        res[0].push_back({1});
        for(int i=1;i<numRows;i++)
        {
            res[i].push_back(1);
            for(int j=1;j<=i;j++)
            {
                int t = 0;
                t+=res[i-1][j-1];
                if(j < res[i-1].size()) t+=res[i-1][j];
                res[i].push_back(t);
            }
        }
        return res;
    }
};