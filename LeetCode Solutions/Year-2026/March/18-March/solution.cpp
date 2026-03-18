class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                curr[j+1] = grid[i][j] + curr[j] + prev[j+1] - prev[j];
                res += curr[j+1]<=k;
            }
            prev = curr;
        }
        return res;
    }
};
