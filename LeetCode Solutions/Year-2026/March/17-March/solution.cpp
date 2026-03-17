class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0] = matrix[0];
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j][i] = matrix[j][i] ? dp[j-1][i] + matrix[j][i] : 0;
            }
        }
        for(int i = 0; i < n; i++){
            sort(dp[i].begin(), dp[i].end());
            for(int j = 0; j < m; j++){
                res = max(res, dp[i][j] * (m-j));
            }
        }
        return res;
    }
};
