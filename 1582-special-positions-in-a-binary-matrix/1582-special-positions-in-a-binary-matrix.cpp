class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j =0; j<m;j++){
                if(mat[i][j] == 1){
                    bool f= true;
                    for(int k = 0;k<n;k++){
                        if(k == i) continue;
                        if(mat[k][j] == 1){
                            f = false;
                            break;
                        }
                    }
                    for(int k = 0;k<m;k++){
                        if(k == j) continue;
                        if(mat[i][k] == 1){
                            f = false;
                            break;
                        }
                    }
                    if(f) ans++;
                }
            }
        }
        return ans;
    }
};