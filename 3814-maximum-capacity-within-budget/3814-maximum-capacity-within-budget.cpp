class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        int ans = 0;
        vector<pair<int,int>>cost;
        for(int i=0;i<n;i++) cost.push_back({costs[i],capacity[i]});
        sort(cost.begin(),cost.end());

        vector<int>pre(n,0);
        pre[0] = cost[0].second;
        for(int i=1;i<n;i++){
            pre[i] = max(cost[i].second,pre[i-1]);
            if(cost[i].first < budget) ans = max(ans,pre[i]);
        }

        for(int i=n-1;i>=0;i--){
            if(cost[i].first >= budget) continue;
            int cos =cost[i].first;
            int cap =cost[i].second;
            int need = budget - cos;
            int l = 0;
            int r = n-1;
            int idx = -1;
            while(l <= r){
                int mid = (r-l)/2 + l;
                if(cost[mid].first < need){
                    idx = mid;
                    l = mid + 1;
                }
                else r = mid -1;
            }
            if(idx != -1){
                if (idx < i) {
                    cap += pre[idx];
                } else if (i > 0) {
                    cap += pre[i - 1];
                }
            }

            ans = max(ans,cap);
        }
        return ans;
    }
};