class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            char a = word[i];
            if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            {
                ans+=(long long)((i+1)*(long long)(n-i));
            }
        }
        return ans;
    }
};