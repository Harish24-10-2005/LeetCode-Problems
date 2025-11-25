class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if( k% 2 == 0 || k % 5 == 0) return -1;
        int rem = 1;
        int cnt = 1;
        while(true)
        {
            if(rem % k == 0) return cnt;
            rem = (rem * 10 + 1) % k;
            cnt++;
        }
        return -1;
    }
};