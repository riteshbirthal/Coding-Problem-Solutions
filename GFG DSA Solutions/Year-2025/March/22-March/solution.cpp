class Solution {
    public:
      int getMax(vector<int>& arr, int n, vector<vector<int>>& dp, int isLastIncluded){
          if(n<0)
              return 0;
          if(n==0)
              return isLastIncluded ? 0 : arr[0];
              
          if(dp[n][isLastIncluded]!=-1)
              return dp[n][isLastIncluded];
              
          int res = 0;
          
          if(n==arr.size()-1){
              res = max(arr[n] + getMax(arr, n-2, dp, 1), getMax(arr, n-1, dp, 0));
          }else{
              res = max(arr[n] + getMax(arr, n-2, dp, isLastIncluded), getMax(arr, n-1, dp, isLastIncluded));
          }
          return dp[n][isLastIncluded] = res;
      }
      
      int maxValue(vector<int>& arr) {
          // your code here
          int n = arr.size();
          vector<vector<int>> dp(n, {-1, -1});
          return getMax(arr, n-1, dp, 0);
      }
  };