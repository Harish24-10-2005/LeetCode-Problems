class Solution {
public:
    long long flowerGame(int n, int m) {
        int o1 = 0;
        int e1 = 0;
        for(int i=1;i<=n;i++)
        {
            if(i%2 == 0) e1+=1;
            else o1+=1;
        }
        int o2 = 0;
        int e2 = 0;
        for(int i=1;i<=m;i++)
        {
            if(i%2 == 0) e2+=1;
            else o2+=1;
        }
        return (long long) o1*e2 + (long long)o2*e1;
    }
};