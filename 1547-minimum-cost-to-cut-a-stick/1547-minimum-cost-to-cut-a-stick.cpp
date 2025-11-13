class Solution {
private:
    int rec(int l,int r,vector<int>&cuts)
    {
        if(l+1>=r) return 0;

        int ans = INT_MAX;
        for(int i=l+1;i<r;i++)
        {
            int c = cuts[r] - cuts[l] + rec(l,i,cuts) + rec(i,r,cuts); 
            ans =min(ans,c);
        }
        return ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return rec(0,cuts.size()-1,cuts);
    }
};