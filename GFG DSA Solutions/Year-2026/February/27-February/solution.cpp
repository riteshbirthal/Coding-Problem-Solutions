class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i+1][j+1] = mat[i][j] + dp[i][j+1] + dp[i+1][j] - dp[i][j];
                for(int k = 0; k <= min(i, j); k++)
                    res += (dp[i+1][j+1] - dp[i+1][j-k] - dp[i-k][j+1] + dp[i-k][j-k])==x;
            }
        }
        return res;
    }
};
