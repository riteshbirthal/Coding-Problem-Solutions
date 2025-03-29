class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int ans = 0, mn = INT_MAX;
        for(int x : prices){
            ans = max(ans, x - mn);
            mn = min(mn, x);
        }
        return ans;
    }
};
