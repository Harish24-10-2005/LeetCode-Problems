class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        vector<int>h(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 1)
                {
                    h[j]+=1;
                }
                else h[j] = 0;
                // cout<<h[j]<<" ";
            }
            // cout<<endl;
            for(int j=0;j<m;j++)
            {
            int minn = INT_MAX;
                for(int r=j;r>=0;r--)
                {
                    if(h[r] == 0) break;
                    minn = min(minn,h[r]);
                    // cout<<minn<<endl;
                    ans+=minn;
                }
            }
        }
        return ans;
    }
};