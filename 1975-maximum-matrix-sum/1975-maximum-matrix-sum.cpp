class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long cnt = 0;
        long long summ = 0;
        int minn = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] < 0){
                    cnt++;
                }
                minn = min(minn,abs(matrix[i][j]));
                summ+=abs(matrix[i][j]);
            }
        }
        if(cnt % 2 == 0){
            return summ;
        }
        return summ - (1LL *2 * minn);
    }
};