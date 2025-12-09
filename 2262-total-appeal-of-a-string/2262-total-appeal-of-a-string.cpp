class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long ans = 0;
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            int l = i + 1;
            if(mpp.count(s[i])){
                l = i - mpp[s[i]];
            }
            int r = n- i;
            ans += (l*r);
            mpp[s[i]] = i;
        }
        return ans;
    }
};