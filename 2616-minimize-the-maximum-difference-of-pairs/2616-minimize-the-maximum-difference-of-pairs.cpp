class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<int>pq;
        for(int i=1;i<n;i+=2){
            pq.push(abs(nums[i-1] - nums[i]));
            if(pq.size()>p) pq.pop();
        } 
        int minn = 0;
        if(p != 0 && pq.size() == p) minn = pq.top();
        while(!pq.empty())pq.pop();
        for(int i=2;i<n;i+=2){
            pq.push(abs(nums[i-1] - nums[i]));
            if(pq.size()>p) pq.pop();
        }
        if(p != 0 && pq.size() == p) minn = min(minn,pq.top());
        return minn;
    }
};