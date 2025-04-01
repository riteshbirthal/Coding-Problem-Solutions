class Solution {
public:
    int func(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vec){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || !grid[i][j] || vec[i][j]) return 0;
        vec[i][j] = 1;
        int ans = 0;
        ans = max(ans, func(grid, i+1, j, vec));
        ans = max(ans, func(grid, i, j+1, vec));
        ans = max(ans, func(grid, i-1, j, vec));
        ans = max(ans, func(grid, i, j-1, vec));
        vec[i][j] = 0;
        return ans + grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> vec(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]) ans = max(ans, func(grid, i, j, vec));
            }
        }
        return ans;
    }
};