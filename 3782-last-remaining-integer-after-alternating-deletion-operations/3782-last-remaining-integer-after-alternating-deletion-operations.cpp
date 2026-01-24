class Solution {
public:
    long long lastInteger(long long n) {
        long long l,r;
        l = 1;
        r = n;
        long long lev = 1;
        while(n != 1){
            long long t1 = n/2;
            if(n%2 != 0){
                t1++;
            }
            if(n%2 == 0){
                r = r-lev;
            }
            lev*=2;
            // cout<<"1st "<<t1<<" "<<l<<" "<<r<<endl;
            long long t2 = t1/2;
            if(t1%2 != 0){
                t2++;
            }
            if(t1%2 == 0){
                l = l+lev;
            }
            // cout<<"2nd "<<t2<<" "<<l<<" "<<r<<endl;
            // if(l == r) return l;
            n = t2;
            lev*=2;
        }
        return l;   
    }
};