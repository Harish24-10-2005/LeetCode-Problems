class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto vec:matrix){
            auto it = lower_bound(vec.begin(),vec.end(),target);\
            if(it == vec.end()) continue;
            if(*it == target) return true;
        }
        return false;
    }
};