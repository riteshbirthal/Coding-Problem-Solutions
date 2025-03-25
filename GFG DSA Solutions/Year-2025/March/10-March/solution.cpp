class Solution {
    public:
      int findEditDistance(string& s1, int n, string& s2, int m, vector<vector<int>>& dp){
          if(n==s1.size() || m==s2.size())
              return s1.size() + s2.size() - n - m;
          if(dp[n][m]!=-1)
              return dp[n][m];
          int res = 1 + findEditDistance(s1, n+1, s2, m, dp); // removing the character from nth position in s1
          if(s1[n]==s2[m])
              res = min(res, findEditDistance(s1, n+1, s2, m+1, dp)); // characters are matched, so no operation needed
          res = min(res, 1 + findEditDistance(s1, n, s2, m+1, dp)); // inserting the mth character to s1
          res = min(res, 1 + findEditDistance(s1, n+1, s2, m+1, dp)); // replacing the nth character of s1 to mth character of s2
          return dp[n][m] = res;
      }
      
      // Function to compute the edit distance between two strings
      int editDistance(string& s1, string& s2) {
          // code here
          int n = s1.size(), m = s2.size(), res;
          vector<vector<int>> dp(n, vector<int>(m, -1));
          res = findEditDistance(s1, 0, s2, 0, dp);
          return res;
      }
  };