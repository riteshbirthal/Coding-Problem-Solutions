class Solution {
public:
    int func(vector<vector<int>>& grid, int column, int row, vector<vector<int>>& dp){
        if(row==grid.size()) return 0;
        if(dp[row][column]!=INT_MAX) return dp[row][column];
        int ans = INT_MAX;
        for(int i = 0; i < grid[row].size(); i++){
            if(i!=column){
                ans = min(ans, grid[row][i] + func(grid, i, row+1, dp));
            }
        }
        return dp[row][column] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX, n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < grid[0].size(); i++){
            ans = min(ans, grid[0][i] + func(grid, i, 1, dp));
        }
        return ans;
    }
};