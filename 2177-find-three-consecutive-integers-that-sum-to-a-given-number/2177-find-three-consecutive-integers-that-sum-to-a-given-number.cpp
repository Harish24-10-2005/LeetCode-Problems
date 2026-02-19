class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long ans = (num -3)/3;
        if((long long)ans+ans+1+ans+2 != num) return {};
        return {ans,ans+1,ans+2};
    }
};