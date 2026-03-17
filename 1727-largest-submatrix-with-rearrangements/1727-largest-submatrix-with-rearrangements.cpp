class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                if(matrix[i][j] == 0){
                    continue;
                }
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        int ans = 0;
        for(int j=0;j<n;j++){
            sort(matrix[j].begin(),matrix[j].end());
            for(int i=0;i<m;i++){
                // if(m - j + 1 >= matrix[j][i]){
                    ans = max(ans,matrix[j][i] * (m - i));
                    // cout<<matrix[j][i] <<" "<< (m - i)<<endl;
                    // cout<<matrix[j][i]<<" ";
                // }
            }
            // cout<<endl;
        }
        return ans;
    }
};