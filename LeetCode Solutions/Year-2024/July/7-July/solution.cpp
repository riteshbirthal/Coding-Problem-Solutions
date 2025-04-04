class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, extra = numBottles%numExchange;
        numBottles *= numExchange;
        while(numBottles >= numExchange){
            ans += numBottles/numExchange;
            numBottles = numBottles/numExchange + numBottles%numExchange;
        }
        return ans;
    }
};