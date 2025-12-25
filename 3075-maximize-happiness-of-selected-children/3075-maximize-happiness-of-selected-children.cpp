class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int>pq;
        for(auto a:happiness){
            pq.push(a);
        }
        int temp = 0;
        while(k!=temp){
            int res = pq.top() - temp;
            if(res>0) ans+=pq.top() - temp;
            pq.pop();
            temp++;
        }
        return ans;
    }
};