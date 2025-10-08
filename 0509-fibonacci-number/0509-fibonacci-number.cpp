class Solution {
public:
    int fib(int n) {
        if(n ==0) return 0;
        int p = 0;
        int p1 = 1;
        for(int i=2;i<=n;i++)
        {
            int cu = p1 + p;
            p = p1;
            p1 = cu;
        }
        return p1;
    }
};