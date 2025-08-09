class Solution {
    double exp(double x,int n)
    {
        if(n == 0) return 1;
        if(n%2 == 0)
        {
            double t = exp(x, n/2);
            return t*t;
        }
        else
        {
            double t = exp(x, n/2);
            return t*t*x;
        }
    }
public:
    double myPow(double x, int n) {
        if(n < 0)
        {
            return 1/exp(x,n);
        }
        return exp(x,n);
    }
};