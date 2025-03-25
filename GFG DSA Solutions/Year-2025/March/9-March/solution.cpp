class Solution {
    public:
      int func(string &s, int n, int m, vector<vector<int>> &dp){
          if(n>=m)
              return 1;
          if(dp[n][m]!=-1)
              return dp[n][m];
          int res = s[n]==s[m] ? func(s, n+1, m-1, dp) : 0;
          func(s, n+1, m, dp);
          func(s, n, m-1, dp);
          return dp[n][m] = res;
      }
      
      int countPS(string &s) {
          // code here
          int n = s.size(), res = 0;
          vector<vector<int>> dp(n, vector<int>(n, -1));
          func(s, 0, n-1, dp);
          for(int i = 0; i < n; i++){
              for(int j = i+1; j < n; j++){
                  if(dp[i][j])
                      res += 1;
              }
          }
          return res;
      }
};