class Solution {
private: 
    int pre(int n)
    {
        if(n == 0) return 1;
        int t = 9;
        int ans = 9;
        for(int i=1;i<n;i++)
        {
            ans*=t;
            t--;
        }
        return ans;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int res = 0;
        for(int i=0;i<=n;i++)
        {
            res+=pre(i);
        }
        return res;
    }
};