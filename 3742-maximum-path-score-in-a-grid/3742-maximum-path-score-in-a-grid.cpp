class Solution {
    int n,m;
private:
    int rec(int i,int j,int k,vector<vector<int>>&grid)
    {
        if(k < 0) return INT_MIN;
        if(i >= n || i < 0 || j >= m || j < 0) return INT_MIN;

        int c = 1;
        if(grid[i][j] == 0) c = 0;

        if(i == n-1 && j == m-1 && k - c >= 0)
        {
            return grid[i][j];
        }




        int ryt = INT_MIN;
        int down = INT_MIN;

        int temp = rec(i,j+1,k-c,grid);
        if(temp != INT_MIN) ryt = grid[i][j] + temp;

        temp = rec(i+1,j,k-c,grid);
        if(temp != INT_MIN) down = grid[i][j] + temp;

        return max(down,ryt);
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        int c = 1;
        if(grid[0][0] == 0) c = 0;
        int ans = rec(0,0,k - c,grid);
        return ans == INT_MIN ? -1 : ans + grid[0][0];

    }
};