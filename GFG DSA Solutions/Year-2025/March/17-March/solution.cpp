class Solution {
    public:
      int isSumPossible(vector<int>& arr, int sum, int n, vector<vector<int>>& dp){
          if(sum==0)
              return 1;
          if(n<0)
              return 0;
          if(dp[sum][n]!=-1)
              return dp[sum][n];
          int res = 0;
          if(arr[n]<=sum)
              res = isSumPossible(arr, sum - arr[n], n-1, dp);
          res = res || isSumPossible(arr, sum, n-1, dp);
          return dp[sum][n] = res;
      }
      
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n = arr.size();
          vector<vector<int>> dp(sum+1, vector<int>(n, -1));
          return isSumPossible(arr, sum, n-1, dp);
      }
  };