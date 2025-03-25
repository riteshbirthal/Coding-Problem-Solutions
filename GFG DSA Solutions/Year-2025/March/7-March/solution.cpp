class Solution {
    public:
      int getLPS(string &s, int start, int end, vector<vector<int>> &dp){
          if(start>=end)
              return start==end;
          if(dp[start][end]!=-1)
              return dp[start][end];
          int res = 1;
          if(s[start]==s[end])
              res = max(res, 2 + getLPS(s, start+1, end-1, dp));
          res = max(res, getLPS(s, start+1, end, dp));
          res = max(res, getLPS(s, start, end-1, dp));
          return dp[start][end] = res;
      }
      
      int longestPalinSubseq(string &s) {
          // code here
          int n = s.size(), res = 1;
          vector<vector<int>> dp(n, vector<int>(n, -1));
          res = getLPS(s, 0, n-1, dp);
          return res;
      }
};