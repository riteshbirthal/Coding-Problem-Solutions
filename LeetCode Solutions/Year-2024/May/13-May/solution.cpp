class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0, count = 0;
        for(int i = 0; i < n; i++){
            if(grid[i][0]==0){
                for(int j = 0; j < m; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        for(int i = 0; i < m; i++){
            count = 0;
            for(int j = 0; j < n; j++){
                count += grid[j][i];
            }
            ans += max(count, n - count) * int(pow(2, m-1-i));
        }
        return ans;
    }
};