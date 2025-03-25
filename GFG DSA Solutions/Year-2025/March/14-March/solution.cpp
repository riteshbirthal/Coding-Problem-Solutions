class Solution {
    public:
      int countWays(vector<int>& coins, int sum, int n, vector<vector<int>>& dp){
          if(n<0)
              return sum==0;
          if(sum==0)
              return 1;
          if(dp[sum-1][n]!=-1)
              return dp[sum-1][n];
          int res = countWays(coins, sum, n-1, dp);
          if(sum>=coins[n])
              res += countWays(coins, sum - coins[n], n, dp);
          return dp[sum-1][n] = res;
      }
      
      int count(vector<int>& coins, int sum) {
          // code here.
          sort(coins.begin(), coins.end());
          int n = coins.size(), res;
          vector<vector<int>> dp(sum, vector<int>(n, -1));
          res = countWays(coins, sum, n-1, dp);
          return res;
      }
  };