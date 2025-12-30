class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // if(n == 3 && m == 3) return 0;
        int ans= 0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                bool f= false;
                unordered_set<int>st;

                st.insert(grid[i][j]);
                st.insert(grid[i][j+1]);
                st.insert(grid[i][j+2]);

                int summ = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                // cout<<summ<<endl;
                for(int r = i+1;r<i+3;r++){
                    int t = 0;
                    for(int c = j;c<j+3;c++){
                        t += grid[r][c];
                        st.insert(grid[r][c]);
                    }
                    if(t != summ){
                        f = true;
                        break;
                    }
                }
                if(f) continue;

                for(int c = j;c<j+3;c++){
                    int t = 0;
                    for(int r = i;r<i+3;r++){
                        t += grid[r][c];
                        st.insert(grid[r][c]);
                    }
                    if(t != summ){
                        f = true;
                        break;
                    }
                }
                if(f) continue;

                int d = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];

                st.insert(grid[i][j]);
                st.insert(grid[i+1][j+1]);
                st.insert(grid[i+2][j+2]);

                if(d != summ) continue;
                d = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

                st.insert(grid[i][j+2]);
                st.insert(grid[i+1][j+1]);
                st.insert(grid[i+2][j]);
                // cout<<d<<endl;
                if(d != summ) continue;
                if(st.size() != 9) continue;
                for(int i=1;i<=9;i++){
                    if(!st.count(i)){
                        f = true;
                        break;
                    }
                }
                if(f) continue;
                ans++;
            }
        }
        return ans;
    }
};