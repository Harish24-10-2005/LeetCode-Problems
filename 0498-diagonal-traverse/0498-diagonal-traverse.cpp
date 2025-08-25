class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        bool f = true;
        for(int i=0;i<n;i++)
        {
            int r = i;
            int c = 0;
            // for (int i = r, j = c; i >= c || j <= r; i--, j++)
            // {
            //     if(f)
            //     {
            //         ans.push_back(mat[i][j]);
            //     }
            //     else
            //     {
            //         ans.push_back(mat[j][i]);
            //     }
                
            // }
            // f = !f;
            vector<int>temp;
            while(r >=0 && c<m)
            {
                temp.push_back(mat[r][c]);
                r--;
                c++;
            }
            if(f)
            {
                ans.insert(ans.end(),temp.begin(),temp.end());
            }
            else
            {
                ans.insert(ans.end(),temp.rbegin(),temp.rend());
            }
            f = !f;
        }
        for(int i=1;i<m;i++)
        {
            int r = n-1;
            int c = i;
            vector<int>temp;
            while(r >=0 && c<m)
            {
                temp.push_back(mat[r][c]);
                r--;
                c++;
            }
            if(f)
            {
                ans.insert(ans.end(),temp.begin(),temp.end());
            }
            else
            {
                ans.insert(ans.end(),temp.rbegin(),temp.rend());
            }
            f = !f;
        }
        return ans;
    }
};