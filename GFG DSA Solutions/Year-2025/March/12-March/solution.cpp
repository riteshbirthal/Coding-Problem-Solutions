class Solution {
    public:
      int getCost(int n, vector<int>& cost, vector<int>& dp){
          if(n<0)
              return 0;
          if(dp[n]!=-1)
              return dp[n];
          return dp[n] = min(cost[n-1] + getCost(n-1, cost, dp), cost[n-2] + getCost(n-2, cost, dp));
      }
      
      int minCostClimbingStairs(vector<int>& cost) {
          // Write your code here
          int res = 0, n = cost.size();
          vector<int> dp(n+1, -1);
          res = getCost(n, cost, dp);
          return res;
      }
  };
  