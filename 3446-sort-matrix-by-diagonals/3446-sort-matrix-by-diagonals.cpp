class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        for(int i = 1;i<n;i++)
        {
            int r = 0;
            int c = i;
            int tr = r;
            int tc = c;
            vector<int>temp;
            while(tc<n)
            {   
                temp.push_back(grid[tr][tc]);
                tr++;
                tc++;
            }
            sort(temp.begin(),temp.end());
            tr = r;
            tc = c;
            while(tc<n)
            {   
                grid[tr][tc] = temp[tr];
                tr++;
                tc++;
            }
        }
        for(int i=0;i<n;i++)
        {
            int r = i;
            int c = 0;
            int tr = r;
            int tc = c;
            vector<int>temp;
            while(tr < n)
            {
                temp.push_back(grid[tr][tc]);
                tr++;
                tc++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            tr= r;
            tc = 0;
            while(tr<n)
            {
                grid[tr][tc] = temp[tc];
                tr++;
                tc++;
            }
        }
        return grid;
    }
};