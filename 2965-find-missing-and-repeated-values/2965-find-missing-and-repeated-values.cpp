class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long gs = 0;
        long long gsq = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                gs+=grid[i][j];
                gsq+=(grid[i][j]*grid[i][j]);
            }
        }
        long long ts = 0;
        long long tsq = 0;
        for(int i=1;i<=n*n;i++)
        {
            ts+=i;
            tsq+=i*i;
        }
        long long x_y = ts - gs;
        long long x2_y2 = tsq - gsq;
        long long x_p_y = x2_y2 / x_y;
        int x = (x_p_y - x_y)/2;
        int y = x_p_y - x;
        return {x,y};

    }
};