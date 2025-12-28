class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int j = m-1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            while(j>= 0 && grid[i][j] < 0){
                cnt++;
                j--;
            }
            // if(cnt == 0) j = n-1;
            cout<<j<<endl;
            ans+=(cnt *(n-i));
        }
        return ans;
    }
};