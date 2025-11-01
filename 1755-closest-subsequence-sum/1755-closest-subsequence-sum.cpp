class Solution {
    vector<int>sub1,sub2;
private:
    void rec(int i,int r,vector<int>&nums,int summ,bool sub)
    {
        if(i == r) 
        {
            if(sub) sub1.push_back(summ);
            else sub2.push_back(summ);
            return;
        }
        rec(i+1,r,nums,summ+nums[i],sub);
        rec(i+1,r,nums,summ,sub);
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n/2;
        rec(0,mid+1,nums,0,true);
        rec(mid+1,n,nums,0,false);
        sort(sub2.begin(),sub2.end());
        int ans = INT_MAX;
        for(auto a:sub1)
        {
            int tar = goal - a;
            int idx = lower_bound(sub2.begin(),sub2.end(),tar) - sub2.begin();
            int b = INT_MAX;
            int c = INT_MAX;
            if(idx < sub2.size()) b = sub2[idx];
            if(idx -1 >= 0) c = sub2[idx-1];
            if(b != INT_MAX)
            {
                ans = min(ans,abs(goal - (a + b)));
            }
            if(c != INT_MAX)
            {
                ans = min(ans,abs(goal - (a + c)));
            }
        }
        return ans;
    }
};