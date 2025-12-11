class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>mx(n+1,INT_MIN),my(n+1,INT_MIN),mix(n+1,INT_MAX),miy(n+1,INT_MAX);
        int ans = 0;
        for(auto a:buildings){
            int x = a[0];
            int y = a[1];
            mx[x] = max(mx[x],y);
            my[y] = max(my[y],x);
            mix[x] = min(mix[x],y);
            miy[y] = min(miy[y],x);
        }
        // for(auto a:mx){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        // for(auto a:mix){
        //     cout<<a<<" ";
        // }
        cout<<endl;
        for(auto a:buildings){
            int x = a[0];
            int y = a[1];
            if(y <  mx[x] && y > mix[x] && x < my[y] && x > miy[y]){
                ans++;
            }
        }
        return ans;
    }
};