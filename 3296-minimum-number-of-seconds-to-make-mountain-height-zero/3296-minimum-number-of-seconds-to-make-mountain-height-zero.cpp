class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();

        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<>>pq;
        for(int i=0;i<n;i++){
            pq.push({workerTimes[i],{i,1}});
        }
        long long maxx = INT_MIN;
        while(mountainHeight){
            auto a = pq.top();
            pq.pop();
            long long time = a.first;
            int idx = a.second.first;
            int x = a.second.second;

            maxx = max(maxx,time);
            
            pq.push({a.first + (1LL * workerTimes[idx] * (x+1)),{idx,x+1}});
            mountainHeight--;
        }
        return maxx;
    }
};