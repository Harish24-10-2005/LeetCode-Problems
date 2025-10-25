class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mpp;
        for(int i=0;i<edges.size();i++)
        {
            int u= edges[i][0];
            int v = edges[i][1];
            mpp[u]++;
            mpp[v]++;
        }
        for(auto a:mpp)
        {
            if(a.second == mpp.size()-1) return a.first;
        }
        return 1;
    }
};