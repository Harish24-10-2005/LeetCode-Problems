class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int cnt = 0;
        int j= 0;
        for(int i=0;i<min(n,m);i++)
        {
            while(j<m && s[j]<g[i]) j++;
            if(j<m && s[j] >= g[i])
            {
                j++; 
                cnt++;
            }
        }
        return cnt;
    }
};