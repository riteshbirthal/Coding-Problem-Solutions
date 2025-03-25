class Solution {
    public:
      int getMaxVal(int W, vector<int>& val, vector<int>& wt, int n, vector<vector<int>>& dp){
          if(W<=0 || n<0)
              return 0;
          if(dp[W-1][n]!=-1)
              return dp[W-1][n];
          int res = getMaxVal(W, val, wt, n-1, dp);
          if(wt[n]<=W)
              res = max(res, val[n] + getMaxVal(W-wt[n], val, wt, n-1, dp));
          return dp[W-1][n] = res;
      }
      
      // Function to return max value that can be put in knapsack of capacity.
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          int n = val.size();
          vector<vector<int>> dp(W, vector<int>(n, -1));
          return getMaxVal(W, val, wt, n-1, dp);
      }
  };
  