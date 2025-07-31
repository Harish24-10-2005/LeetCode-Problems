class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        int n = s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++)
        {
            while(l<i && mpp[s[i]] >0)
            {
                mpp[l]--;
                l++;
            }
            ans = max(ans,i-l+1);
            mpp[s[i]]++;
        }   
        return ans;
    }
};