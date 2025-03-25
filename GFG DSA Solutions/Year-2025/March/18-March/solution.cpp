class Solution {
    public:
      int isPossible(vector<int>& arr, int n, int sum, vector<vector<int>>& dp){
          if(sum==0)
              return 1;
          if(sum<0 || n<0)
              return 0;
          if(dp[sum][n]!=-1)
              return dp[sum][n];
          int res = 0;
          if(arr[n]<=sum)
              res = isPossible(arr, n-1, sum - arr[n], dp);
          res = res || isPossible(arr, n-1, sum, dp);
          return dp[sum][n] = res;
      }
      
      bool equalPartition(vector<int>& arr) {
          // code here
          int sum = 0, n = arr.size();
          for(int x : arr)
              sum += x;
          if(sum%2)
              return false;
          vector<vector<int>> dp(sum/2+1, vector<int>(n, -1));
          return isPossible(arr, n-1, sum/2, dp);
      }
  };