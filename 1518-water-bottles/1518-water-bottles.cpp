class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        
        while(numBottles >= numExchange)
        {
            int f = numBottles/numExchange;
            ans+=f;
            // cout<<f<<endl;
            int r = numBottles%numExchange;
            numBottles = f+r;
        }

        return ans;
    }
};