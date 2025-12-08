class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long ans = 0;
        vector<int>gain;
        for(int i=0;i<technique1.size();i++)
        {
            ans+=technique2[i];
            gain.push_back(technique1[i] - technique2[i]);
        }
        sort(gain.begin(),gain.end(),greater<int>());
        int i = 0;
        while(i<gain.size() && gain[i] > 0){
            i++;
        }
        int t = max(k,i);
        for(int i=0;i<t;i++) ans+=gain[i];
        return ans;
    }
};