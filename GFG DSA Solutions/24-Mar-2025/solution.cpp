class Solution {
    public:
      int countMulti(vector<int>& arr, int a, int b, vector<vector<int>>& dp){
          if(b-a<2)
              return 0;
          if(dp[a][b]!=-1)
              return dp[a][b];
          int res = INT_MAX;
          for(int i = a+1; i < b; i++){
              res = min(res, countMulti(arr, a, i, dp) + countMulti(arr, i, b, dp) + arr[a]*arr[i]*arr[b]);
          }
          return dp[a][b] = res;
      }
      
      int matrixMultiplication(vector<int> &arr) {
          // code here
          int n = arr.size();
          vector<vector<int>> dp(n, vector<int>(n , -1));
          return countMulti(arr, 0, n-1, dp);
      }
};