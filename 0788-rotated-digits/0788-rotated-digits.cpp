class Solution {
public:
    int rotatedDigits(int n) {
        set<int>same{0,1,8},diff{2,5,6,9};
        int cnt = 0;
        for(int i = 0;i<=n;i++){
            int temp = i;
            bool f = false;
            while(temp != 0){
                int r = temp % 10;
                if(diff.count(r)){
                    f = true;
                }
                else{
                    if(!same.count(r)) {
                        f = false;
                        break;
                    }
                }
                temp/=10;
            }
            if(f) cnt++;
        }
        return cnt;
    }
};