class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), x = n - 1, y = 0, count = 0;
        while (x >= 0 && y < m) {
            if (grid[x][y] >= 0) {
                y += 1;
            } else {
                count += m - y;
                x -= 1;
            }
        }
        return count;
    }
};
