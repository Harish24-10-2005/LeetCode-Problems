class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>st;
        for(auto a:nums){
            st.insert(a);
        }
        int n  = nums[0].size();
        int p = pow(2,n);
        for(int bit=0;bit<p;bit++){
            string temp(n,'0');
            for(int i=0;i<n;i++){
                if(bit & (1<<i)){
                    temp[i] = '1';
                }
            }
            if(!st.count(temp)) return temp;
        }
        return "0";
    }
};