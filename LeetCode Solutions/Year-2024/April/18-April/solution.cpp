class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0, n = grid.size(), m = grid[0].size(), temp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    temp = 0;
                    if(i-1>=0 && grid[i-1][j]) temp++;
                    if(i+1<n && grid[i+1][j]) temp++;
                    if(j-1>=0 && grid[i][j-1]) temp++;
                    if(j+1<m && grid[i][j+1]) temp++;
                    perimeter += 4 - temp;
                }
            }
        }
        return perimeter;
    }
};