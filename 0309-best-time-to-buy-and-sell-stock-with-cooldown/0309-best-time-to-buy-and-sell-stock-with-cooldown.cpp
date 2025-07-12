class Solution {
    int rec(int i,int buy,int n,vector<int>&p)
    {
        if(i == n-1)
        {
            if(buy) return 0;
            return p[n-1];
        }
        int ans = 0;
        if(buy)
        {
            if(i+1 < n)ans = max(-p[i] + rec(i+1,0,n,p),rec(i+1,1,n,p));
        }
        else
        {
            ans = max(p[i]+rec(i+2,1,n,p),rec(i+1,0,n,p));
        }
        return ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return rec(0,1,n,prices);
    }
};