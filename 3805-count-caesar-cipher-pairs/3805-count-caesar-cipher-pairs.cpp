class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long ans = 0;
        unordered_map<string,long long>mpp;
        for(string s:words){
            string t = "";
            for(int i=1;i<s.size();i++){
                int diff = s[i] - s[i - 1];
                if(diff < 0) diff  = 26 + (diff);
                while(diff != 0){
                    int r = diff % 10;
                    diff /= 10;
                    t += (r + '0');
                }
                t+="#";
            }
            // cout<<t<<endl;
            if(mpp.count(t)){
                ans += mpp[t];
            }
            mpp[t]++;
        }
        return ans;
    }
};