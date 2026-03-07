class Solution {
  public:
    int getWays(int m, int n, int x, vector<vector<vector<int>>>& dp){
        if(n==0)
            return x==0;
        if(x<0)
            return 0;
        if(dp[m][n][x]!=-1)
            return dp[m][n][x];
        int res = 0;
        for(int i = 1; i <= m; i++)
            res += getWays(m, n-1, x-i, dp);
        return dp[m][n][x] = res;
    }
    
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(x+1, -1)));
        int res = getWays(m, n, x, dp);
        return res;
    }
};
