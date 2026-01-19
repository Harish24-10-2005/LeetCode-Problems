class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int maxx = 0;
        bool f = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int summ = 0;
                int prei = i+maxx;
                int prej = j+maxx;
                if(prei >= n) break;
                if(prej >= m) break;
                for(int r = i;r<=prei;r++){
                    for(int c = j;c<=prej;c++){
                        summ+= mat[r][c];
                    }
                }
                if(summ > threshold) continue;
                f = true;
                // cout<<summ<<endl;
                while(summ < threshold){
                    if(prei + 1 >= n) break;
                    if(prej + 1 >= m) break;
                    for(int r = i;r<=prei+1;r++){
                        summ+= mat[r][prej+1];
                    }
                    cout<<summ<<endl;
                    for(int c = j;c<=prej;c++){
                        summ+= mat[prei+1][c];
                    }
                    cout<<summ<<endl;
                    prei++;
                    prej++;
                    // maxx++;
                    if(summ <= threshold) maxx++;
                }
                // cout<<summ<<" "<<maxx<<" "<<i<<" "<<j<<endl;
            }
        }
        if(!f) return 0;
        return maxx + 1;
    }
};