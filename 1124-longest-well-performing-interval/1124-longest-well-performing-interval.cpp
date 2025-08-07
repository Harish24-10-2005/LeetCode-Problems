class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++)
        {
            if(hours[i] > 8) temp[i] = 1;
            else temp[i] = -1;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int a = 0;
            int j=i;
            for(j=i;j<n;j++)
            {
                a+=temp[j];
                if(a>0) ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};