class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size();
        int m = ws.size();
        int minnland = INT_MAX;
        int minnwater = INT_MAX;
        for(int i=0;i<n;i++){
            int t = ls[i] + ld[i];
            minnland = min(minnland,t);
        }
        for(int i=0;i<m;i++){
            int t = ws[i] + wd[i];
            minnwater = min(minnwater,t);
        }
        int ans = INT_MAX;
        // cout<<minnland<<" "<<minnwater<<endl;
        for(int i=0;i<m;i++){
            int temp = minnland;
            if(ws[i] > minnland){
                temp = temp + (ws[i] - temp);
                temp += wd[i];
            }else{
                temp += wd[i];
            }
            ans = min(temp,ans);
        }
        for(int i=0;i<n;i++){
            int temp = minnwater;
            if(ls[i] > minnwater){
                temp = temp + (ls[i] - temp);
                temp += ld[i];
            }else{
                temp += ld[i];
            }
            ans = min(temp,ans);
        }
        return ans;
    }
};