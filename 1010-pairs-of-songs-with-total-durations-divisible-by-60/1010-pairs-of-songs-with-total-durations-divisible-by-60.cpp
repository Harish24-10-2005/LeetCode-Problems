class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mpp;
        int n = time.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(mpp.find((60 - (time[i]%60))%60)!=mpp.end())
            {
                ans+= mpp[(60 - (time[i] % 60))%60];
            }
            mpp[time[i] % 60]++;
        }
        return ans;
    }
};