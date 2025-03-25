class Solution {
    public:
      int getWays(string &digits, int n, vector<int>& dp){
          if(n<0)
              return 1;
          if(dp[n]!=-1)
              return dp[n];
          int res = 0, num = stoi(digits.substr(n, 1));
          if(num && num<27){
              res = getWays(digits, n-1, dp);
          }
          if(n && digits[n-1]!='0' && stoi(digits.substr(n-1, 2))<27){
              res += getWays(digits, n-2, dp);
          }
          return dp[n] = res;
      }
      
      int countWays(string &digits) {
          // Code here
          int n = digits.size(), res, notPossible = 0, num;
          for(int i = 0; i < n-1; i++){
              num = stoi(digits.substr(i, 2));
              if(num==0 || (num%10==0 && num>20))
                  notPossible = 1;
          }
          if(digits[0]=='0' || notPossible)
              return 0;
          vector<int> dp(n, -1);
          res = max(0, getWays(digits, n-1, dp));
          return res;
      }
  };