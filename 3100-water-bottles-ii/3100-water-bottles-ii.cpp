class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles >= numExchange)
        {
            numBottles -= numExchange;
            ans++;
            numBottles++;
            // int s = numBottles % numExchange;
            // numBottles = f + s;
            numExchange++;
        }
        return ans;

    }
};