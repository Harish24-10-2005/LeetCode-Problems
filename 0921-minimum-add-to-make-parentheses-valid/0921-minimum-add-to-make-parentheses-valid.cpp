class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(ch == ')') continue;
            for(int j=i+1;j<n;j++)
            {
                if(s[j] == ')' && !vis[j])
                {
                // cout<<i<<endl;
                    vis[i] = 1;
                    vis[j] = 1;
                    break;
                }
            }
            // cout<<vis[i]<<endl;
        }
        for(auto a:vis)
        {
            // cout<<a<<endl;
            if(a == 0) cnt++;
        } 
        return cnt;
    }
};