class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int ans = 0;
        int l = 0;
        for(int i=0;i<n;i++)
        {
            mpp[s[i]]++;
            while(l<i && mpp[s[i]] > 1)
            {
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};