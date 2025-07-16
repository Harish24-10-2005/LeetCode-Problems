class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();

        if(n<3) return 0;
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);

        for(int i=1;i<n;i++)
        {
            if(arr[i] > arr[i-1]) dp1[i] = dp1[i-1] + 1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i] > arr[i+1]) dp2[i] = dp2[i+1] + 1;
        }

        int m = 0;
        for(int i=0;i<n;i++)
        {
            if(dp1[i] != 0 && dp2[i]!=0) m = max(m,dp1[i] + dp2[i]);
        }

        return m == 0 ? 0 : m+1;
    }
};