class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>r(n,0);
        vector<int>c(m,0);
        for(int i=0;i<n;i++)
        {
            int temp = 0;
            for(int j=0;j<m;j++)
            {
                c[j]+=grid[i][j];
                temp+=grid[i][j];
            }
            r[i] = temp;
        }
        int tempn = n;
        int tempm = m;
        int i = 0;
        int j = 0;
        while(i<n && r[i] == 0)
        {
            i++;
            tempn--;
        }
        while(j<m && c[j] == 0)
        {
            j++;
            tempm--;
        }
        i = n-1;
        j = m-1;
        while(i>=0 && r[i] == 0)
        {
            i--;
            tempn--;
        }
        while(j>=0 && c[j] == 0)
        {
            j--;
            tempm--;
        }
        return tempn*tempm;
    }
};