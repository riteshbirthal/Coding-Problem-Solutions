class Solution {
    public:
      int getWays(string& s, int a, int b, char val, vector<vector<vector<int>>>& dp){
          if(a==b)
              return s[a]==val;
          if(dp[a][b][val=='T']!=-1)
              return dp[a][b][val=='T'];
          int res = 0;
          for(int i = a+1; i < b; i += 2){
              int tT, tF, fT, fF;
              tT = getWays(s, a, i-1, 'T', dp) * getWays(s, i+1, b, 'T', dp);
              tF = getWays(s, a, i-1, 'T', dp) * getWays(s, i+1, b, 'F', dp);
              fT = getWays(s, a, i-1, 'F', dp) * getWays(s, i+1, b, 'T', dp);
              fF = getWays(s, a, i-1, 'F', dp) * getWays(s, i+1, b, 'F', dp);
              if(s[i]=='&'){
                  res += val=='T' ? tT : (tF + fT + fF);
              }else if(s[i]=='|'){
                  res += val=='T' ? (tF + fT + tT) : fF;
              }else{
                  res += val=='T' ? (fT + tF) : (tT + fF);
              }
          }
          return dp[a][b][val=='T'] = res;
      }
      
      int countWays(string &s) {
          // code here
          int n = s.size();
          vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, {-1, -1}));
          return getWays(s, 0, n-1, 'T', dp);
      }
};