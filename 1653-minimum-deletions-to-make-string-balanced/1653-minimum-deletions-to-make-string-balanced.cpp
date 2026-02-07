class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int a = 0,b = 0;
        bool f = false;
        vector<int>pre(n,0),suf(n,0);
        for(int i=0;i<n;i++){
            if(s[i] == 'b') b++;
            pre[i] = b;
        }
        f = false;
        for(int i=n-1;i>=0;i--){
            if(s[i] == 'a') a++;
            suf[i] = a;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans= min(ans,pre[i] + suf[i] - 1);
        }
        return ans;
    }
};