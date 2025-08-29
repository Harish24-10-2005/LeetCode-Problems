class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        // int ans = 0;
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<dimensions.size();i++)
        {
            int l = dimensions[i][0] * dimensions[i][0];
            int w = dimensions[i][1] * dimensions[i][1];
            double len = sqrt(l + w);
            pq.push({len,dimensions[i][0] * dimensions[i][1]});
        }
        return pq.top().second;
    }
};