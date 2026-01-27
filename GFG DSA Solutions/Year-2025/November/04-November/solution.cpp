class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+3, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n-1; i++){
            dp[i+1] = min(dp[i+1], abs(height[i+1]-height[i]) + dp[i]);
            if(i+2<n)
                dp[i+2] = min(dp[i+2], abs(height[i+2]-height[i]) + dp[i]);
        }
        return dp[n-1];
    }
};
