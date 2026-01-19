class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        sort(towers.begin(),towers.end(),[](auto &a,auto &b){
            if(a[2] == b[2]){
                if(a[0] == b[0]) return a[1]<b[1];
                return a[0]<b[0];
            }
            return a[2] > b[2];
        });
        for(auto a:towers){
            int x = a[0];
            int y = a[1];
            int dist = abs(center[0] - x) + abs(center[1] - y);
            if(abs(dist) > radius) continue;
            return {x,y}; 
        }
        return {-1,-1};
    }
};