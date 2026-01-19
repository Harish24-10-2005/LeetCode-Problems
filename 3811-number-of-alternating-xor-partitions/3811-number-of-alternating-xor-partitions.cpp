class Solution {
private:
    int MOD = 1e9 + 7;
    unordered_map<long long,int>mpp;
    int n;
    int rec(int i,bool f,int e,vector<int>&nums,int t1,int t2){
        if(i == n){
            if((f && (e == t1)) || (!f && (e == t2))) return 1;
            return 0;
        }
        long long key =((long long)i << 32) |((long long)e << 1) | f;
        if(mpp.count(key)) return mpp[key];

        int take = 0;
        if((f && (e == t1)) || (!f && (e == t2))){
            take = rec(i+1,!f,nums[i],nums,t1,t2);
        }
        int nt = rec(i+1,f,e ^ nums[i],nums,t1,t2);
        return mpp[key]=(take + nt)  % MOD;
    }
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        n = nums.size();
        return rec(0,true,0,nums,target1,target2);
    }
};