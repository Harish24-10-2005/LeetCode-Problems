class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        for(int i=n-1;i>=0;i--){
            int d = digits[i] + carry;
            if(i == n-1) d++;
            digits[i] = d % 10;
            // cout<<d/10<<endl;
            carry = d/10;
        }
        if(carry){
            for(int i=0;i<n;i++){
                int temp = digits[i];
                digits[i] = carry;
                carry = temp;
            }
            digits.push_back(carry);
        }
        return digits;
    }
};