class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        vector<int> res;
        int n = mat.size(), m = mat[0].size(), r1, c1, r2, c2;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i+1][j+1] = mat[i][j] + dp[i+1][j] + dp[i][j+1] - dp[i][j];
            }
        }
        for(auto &q : queries){
            r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            res.push_back(dp[r2+1][c2+1] + dp[r1][c1] - dp[r1][c2+1] - dp[r2+1][c1]);
        }
        return res;
    }
};
