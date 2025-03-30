class Solution {
public:
    int func(vector<vector<int>>& v, int n, int m, int r, int c, vector<vector<int>> &dp){
        if(c>=m-1) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        int ans = 0;
        if(r>0 && v[r-1][c+1]>v[r][c]){
            ans = max(ans, 1 + func(v, n, m, r-1, c+1, dp));
        }
        if(v[r][c+1]>v[r][c]){
            ans = max(ans, 1 + func(v, n, m, r, c+1, dp));
        }
        if(r<n-1 && v[r+1][c+1]>v[r][c]){
            ans = max(ans, 1 + func(v, n, m, r+1, c+1, dp));
        }
        return dp[r][c] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            ans = max(ans, func(grid, n, m, i, 0, dp));
        }
        return ans;
    }
};