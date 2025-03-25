class Solution {
    public:
      int getMin(vector<int>& coins, int sum, int n, vector<vector<int>>& dp){
          if(sum==0)
              return 0;
          if(sum<0 || n<0)
              return INT_MAX;
          if(dp[sum-1][n]!=-1)
              return dp[sum-1][n];
          int res = getMin(coins, sum, n-1, dp);
          if(coins[n]<=sum){
              int r1 = getMin(coins, sum-coins[n], n, dp);
              res = min(res, r1==INT_MAX ? r1 : 1 + r1);
          }
          return dp[sum-1][n] = res;
      }
      
      int minCoins(vector<int> &coins, int sum) {
          // code here
          sort(coins.begin(), coins.end());
          int n = coins.size(), res;
          vector<vector<int>> dp(sum, vector<int>(n, -1));
          res = getMin(coins, sum, n-1, dp);
          return res==INT_MAX ? -1 : res;
      }
  };