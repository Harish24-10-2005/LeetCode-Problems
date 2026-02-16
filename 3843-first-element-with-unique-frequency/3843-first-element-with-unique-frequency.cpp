class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mpp,ans;
        for(int i:nums){
            mpp[i]++;
        }
        for(auto a:mpp){
            ans[a.second]++;
        }
        
        for(int i:nums){
            if(ans[mpp[i]] == 1 ) return i;
        }
        return -1;
    }
};