class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maz = 0;
        int cnt = 0;
        for(int i:seats){
            if(i == 0) cnt++;
            else{
                cnt = 0;
            }
            maz = max(maz,cnt);
        }
        maz = (maz%2 == 0 ? maz/2 : (maz/2) + 1);
        cnt = 0;
        int i=0;
        while(i<n && seats[i]!=1){
            cnt++;
            i++;
        }
        maz = max(maz,cnt);
        cnt = 0;
        i=n-1;
        while(i>=0 && seats[i]!=1){
            cnt++;
            i--;
        }
        maz = max(maz,cnt);

        return maz;
    }
};