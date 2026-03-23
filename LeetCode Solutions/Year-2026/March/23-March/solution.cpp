class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long res = INT_MIN, MOD = 1e9+7, a, b, c, d, x;
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m));
        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 1; i < n; i++)
            dp[i][0] = {(long long)grid[i][0] * dp[i-1][0].first, (long long)grid[i][0] * dp[i-1][0].first};
        for(int j = 1; j < m; j++)
            dp[0][j] = {(long long)grid[0][j] * dp[0][j-1].first, (long long)grid[0][j] * dp[0][j-1].first};
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                a = dp[i-1][j].first, b = dp[i-1][j].second;
                c = dp[i][j-1].first, d = dp[i][j-1].second;
                x = grid[i][j];
                dp[i][j] = {min(x*a, min(x*b, min(x*c, x*d))), max(x*a, max(x*b, max(x*c, x*d)))};
            }
        }
        res = dp[n-1][m-1].second;
        return res<0 ? -1 : res%MOD;
    }
};
