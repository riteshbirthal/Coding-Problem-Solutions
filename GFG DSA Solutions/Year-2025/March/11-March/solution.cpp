class Solution {
    public:
      int func(int n, vector<int>& dp){
          if(n<2)
              return 1;
          if(dp[n]!=-1)
              return dp[n];
          return dp[n] = func(n-1, dp) + func(n-2, dp);
      }
      
      int countWays(int n) {
          // your code here
          vector<int> dp(n+1, -1);
          return func(n, dp);
      }
  };
  
  