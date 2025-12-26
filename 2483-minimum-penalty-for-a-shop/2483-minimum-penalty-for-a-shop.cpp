class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.size();
        vector<int>sufY(n),sufN(n);
        sufY[n-1] = c[n-1] == 'Y'? 1:0;
        sufN[n-1] = c[n-1] == 'N'? 1:0;
        int nn = c[n-1] == 'N'? 1:0;
        for(int i=n-2;i>=0;i--){
            sufY[i] = sufY[i+1];
            sufN[i] = sufN[i+1];
            if(c[i] == 'Y'){
                sufY[i] = 1 + sufY[i+1];
            }
            else{
                nn++;
                sufN[i] = 1 + sufN[i+1];
            }
        }
        cout<<nn<<endl;
        if(nn == n) return 0;
        int minn = INT_MAX;
        int idx = n-1;
        for(int i=n-1;i>=0;i--){
            int y = 0;
            if(i!= n-1) y = sufY[i+1];
            int n = sufN[0]-sufN[i];
            // cout<<y<<" "<<n<<endl;
            if((y + n) <= minn){
                idx = i;
                // cout<<i<<endl;
                minn = y + n;
            }
    
        }
        return idx + 1;
    }
};