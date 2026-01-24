class Solution {
  public:
    int calculateWays(int left, int right, vector<vector<int>>& dp){
        if(left>right)
            return 0;
        if(left==0)
            return 1;
        if(dp[left][right]!=-1)
            return dp[left][right];
        int res = calculateWays(left, right-1, dp) + calculateWays(left-1, right, dp);
        return dp[left][right] = res;
    }
    
    int findWays(int n) {
        // code here
        if(n%2)
            return 0;
        n = n/2;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int res = calculateWays(n, n, dp);
        return res;
    }
};
