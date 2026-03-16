class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<int>top;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                for(int cnt=0;cnt<=n/2;cnt++){
                    if(cnt == 0){
                        top.insert(grid[i][j]);
                        while(top.size() > 3){
                            top.erase(top.begin());
                        }
                        continue;
                    }
                    int temp = 0;
                    int x1 = i + cnt;
                    int y1 = j - cnt;

                    int x2 = i + cnt;
                    int y2 = j + cnt;

                    int x3 = i + 2 * cnt;
                    int y3 = j;

                    if(x1 < n && y1 < m && x1 >=0 && y1 >= 0 && x2 < n && x3 < n && y2 < m && y3 < m && x2 >= 0 && x3 >= 0 && y2 >=0 && y3 >= 0 ){
                        for(int k=i;k<=x1;k++){
                            temp += grid[k][j - (k-i)];
                        }
                        for(int k=x1;k<=x3;k++){
                            temp += grid[k][y1 + (k -x1)];
                        }
                        for(int k=i;k<=x2;k++){
                            temp += grid[k][j + (k - i)];
                        }
                        for(int k=x2;k<=x3;k++){
                            temp += grid[k][y2-(k-x2)];
                        }
                        temp -=(grid[i][j] + grid[x1][y1] + grid[x2][y2] + grid[x3][y3]);
                        top.insert(temp);
                        while(top.size() > 3){
                            top.erase(top.begin());
                        }
                    }
                }
            }
        }
        vector<int> ans(top.rbegin(), top.rend());
        return ans;
    }
};