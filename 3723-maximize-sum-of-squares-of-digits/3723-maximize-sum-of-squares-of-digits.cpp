class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        while(num!=0)
        {
            int r = 0;
            if(sum > 9) 
            {
                r = 9;
            }
            else r = sum % 9;
            res+= (r + '0');
            sum-=r;
            num--;
        }
        // cout<<res<<endl;
        if(sum > 0) return "";
        return res;
    }
};