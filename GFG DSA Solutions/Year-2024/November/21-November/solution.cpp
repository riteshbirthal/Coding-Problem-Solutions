
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int ans = 0, n = prices.size();
        for(int i = 1; i < n; i++){
            ans += max(0, prices[i] - prices[i-1]);
        }
        return ans;
    }
};
