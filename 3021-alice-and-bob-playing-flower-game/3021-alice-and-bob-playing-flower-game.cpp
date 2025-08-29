class Solution {
public:
    long long flowerGame(int n, int m) {
        int o1 = 0;
        int e1 = 0;
        // for(int i=1;i<=n;i++)
        // {
        //     if(i%2 == 0) e1+=1;
        //     else o1+=1;
        // }
        int o2 = 0;
        int e2 = 0;
        // for(int i=1;i<=m;i++)
        // {
        //     if(i%2 == 0) e2+=1;
        //     else o2+=1;
        // }
        if(n%2 == 0)
        {
            o1 = n/2;
            e1 = n/2;
        }
        else
        {
            o1 = (n/2) + 1;
            e1 = o1-1;
        }
        if(m%2 == 0)
        {
            o2 = m/2;
            e2 = m/2;
        }
        else
        {
            o2= (m/2) +1;
            e2 = o2-1;
        }
        long long a = (long long)o1*e2 + (long long) o2*e1 ;
        return a<0?1:a;
    }
};