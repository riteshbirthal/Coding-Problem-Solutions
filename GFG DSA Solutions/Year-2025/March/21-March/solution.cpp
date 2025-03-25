class Solution {
    public:
      int getMax(vector<int>& arr, int n, vector<int>& dp){
          if(n<0)
              return 0;
          if(dp[n]!=-1)
              return dp[n];
          int res = max(arr[n] + getMax(arr, n-2, dp), getMax(arr, n-1, dp));
          return dp[n] = res;
      }
      
      int findMaxSum(vector<int>& arr) {
          // code here
          int n = arr.size();
          vector<int> dp(n, -1);
          return getMax(arr, n-1, dp);
      }
  };