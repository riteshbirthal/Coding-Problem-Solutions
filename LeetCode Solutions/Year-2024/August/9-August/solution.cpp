class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y){
        vector<int> digits(10, 0), sums(8, 0);
        // checking for repeatation of digits
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(grid[i+x][j+y]<1 || grid[i+x][j+y]>9 || digits[grid[i+x][j+y]])
                    return false;
                else
                    digits[grid[i+x][j+y]]++;
        // columns sum
        sums[0] = grid[x][y] + grid[x+1][y] + grid[x+2][y];
        sums[1] = grid[x][y+1] + grid[x+1][y+1] + grid[x+2][y+1];
        sums[2] = grid[x][y+2] + grid[x+1][y+2] + grid[x+2][y+2];
        // rows sum
        sums[3] = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        sums[4] = grid[x+1][y] + grid[x+1][y+1] + grid[x+1][y+2];
        sums[5] = grid[x+2][y] + grid[x+2][y+1] + grid[x+2][y+2];
        // diagonal sum
        sums[6] = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        sums[7] = grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2];
        // checking sum equality
        for(int i = 1; i < 8; i++)
            if(sums[i]!=sums[i-1])
                return false;
        return true;                    
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i = 0; i < n - 2; i++){
            for(int j = 0; j < m - 2; j++){
                if(check(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};