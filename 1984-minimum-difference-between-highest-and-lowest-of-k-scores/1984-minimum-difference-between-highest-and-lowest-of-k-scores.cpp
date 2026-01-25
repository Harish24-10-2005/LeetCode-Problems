class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxx = INT_MIN;
        int minn = INT_MAX;
        int ans = INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minpq;
        priority_queue<pair<int,int>>maxpq;
        for(int i=0;i<k;i++){
            minpq.push({nums[i],i});
            maxpq.push({nums[i],i});
        }
        ans = min(ans,maxpq.top().first - minpq.top().first);

        for(int i=k;i<nums.size();i++){
            while(!maxpq.empty() && maxpq.top().second <= (i-k)){
                maxpq.pop();
            }
            while(!minpq.empty() && minpq.top().second <= (i-k)){
                minpq.pop();
            }
            minpq.push({nums[i],i});
            maxpq.push({nums[i],i});
            cout<<maxpq.top().first<<" "<<minpq.top().first<<endl;
            ans = min(ans,maxpq.top().first - minpq.top().first);
        }
        return ans;
    }
};