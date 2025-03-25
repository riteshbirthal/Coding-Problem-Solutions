class Solution {
    public:
      int getLCS(string &s1, string &s2, int n1, int n2, vector<vector<int>>& dp){
          if(n1==s1.size() || n2==s2.size())
              return 0;
          if(dp[n1][n2]!=-1)
              return dp[n1][n2];
          if(s1[n1]==s2[n2])
              return dp[n1][n2] = 1 + getLCS(s1, s2, n1+1, n2+1, dp); 
          return dp[n1][n2] = max(getLCS(s1, s2, n1+1, n2, dp), getLCS(s1, s2, n1, n2+1, dp));
      }
      
      int lcs(string &s1, string &s2) {
          // code here
          int n1 = s1.size(), n2 = s2.size(), res = 0;
          vector<vector<int>> dp(n1, vector<int>(n2, -1));
          res = getLCS(s1, s2, 0, 0, dp);
          return res;
      }
};