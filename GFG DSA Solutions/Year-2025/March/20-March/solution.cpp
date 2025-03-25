class Solution {
    public:
      
      int maxProfit(vector<int> &prices) {
          // code here
          int n = prices.size(), res = 0, mn = 1e9, mx = -1e9;
          vector<int> dp(n, 0); 
          for(int i = 0; i < n; i++){
              if(i) dp[i] = dp[i-1];
              dp[i] = max(dp[i], prices[i]-mn);
              mn = min(mn, prices[i]);
          }
          for(int i = n-1; i > 0; i--){
              res = max(res, dp[i-1] + max(0, mx-prices[i]));
              mx = max(mx, prices[i]);
          }
          return max(res, 0);
      }
  };