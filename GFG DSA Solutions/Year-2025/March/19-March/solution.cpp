class Solution {
    public:
      int getProfit(vector<int>& prices, int n, int k, int isIncluded, vector<vector<vector<int>>>& dp){
          if(n<0 || k==0)
              return isIncluded ? -1e9 : 0;
          if(dp[k][n][isIncluded]!=-1)
              return dp[k][n][isIncluded];
          int res = 0;
          if(isIncluded){
              res = max(-prices[n] + getProfit(prices, n-1, k-1, 0, dp), getProfit(prices, n-1, k, isIncluded, dp));
          }else{
              res = max(prices[n] + getProfit(prices, n-1, k, 1, dp), getProfit(prices, n-1, k, isIncluded, dp));
          }
          return dp[k][n][isIncluded] = res;
      }
      
      int maxProfit(vector<int>& prices, int k) {
          // code here
          int n = prices.size(), res;
          vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(n, {-1, -1}));
          res = getProfit(prices, n-1, k, 0, dp);
          return max(res, 0);
      }
  };