class Solution {
  public:
    int getMin(int sum, int n, vector<vector<int>>& dp){
        if(sum==0)
            return 0;
        if(n==1)
            return sum;
        if(dp[sum][n]!=-1)
            return dp[sum][n];
        int res = getMin(sum, n-1, dp);
        if(n*n<=sum)
            res = min(res, 1 + getMin(sum - n*n, n, dp));
        return dp[sum][n] = res;
    }
    
    int minSquares(int n) {
        // Code here
        vector<vector<int>> dp(n+1, vector<int>(sqrt(n)+2, -1));
        return getMin(n, sqrt(n) + 1, dp);
    }
};
