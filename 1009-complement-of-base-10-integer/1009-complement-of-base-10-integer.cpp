class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        unsigned int num = n;
        int len = std::bit_width(num);
        // cout<<len<<endl;
        if(len == 0) len = 1;
        for(int bit =0;bit<len;bit++){
            if(!((1<<bit) & n)){
                ans+=pow(2,bit);
            }
        }
        return ans;
    }
};