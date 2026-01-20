class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        unordered_set<int>st1;
        for(int i:hBars) st1.insert(i);

        unordered_set<int>st2;
        for(int i:vBars) st2.insert(i);

        int m1 = 0;
        int cnt1 = 1;
        for(int i=1;i<=n+2;i++){
            if(st1.count(i)){
                cnt1++;
            }
            else{
                cnt1 = 1;
            }
            m1 = max(m1,cnt1);
        }
        int m2 = 0;
        int cnt2 = 1;
        for(int i=1;i<=m+2;i++){
            if(st2.count(i)){
                cnt2++;
            }
            else{
                cnt2 = 1;
            }
            m2 = max(m2,cnt2);
        }
        return min(m1,m2) * min(m1,m2);
    }
};