class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = n*n;
        // cout<<t<<endl;
        vector<vector<int>>res(n,vector<int>(n,0));
        int st = 1;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        while(left <= right)
        {
            for(int i=left;i<=right;i++)
            {
                res[top][i] = st;
                st++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                res[i][right] = st;
                st++;
            }
            right--;
            for(int i=right;i>=left;i--)
            {
                res[bottom][i] = st;
                st++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                res[i][left] = st;
                st++;
            }
            left++;
        }
        return res;
    }
};