class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> vec;
        for(int i = x; i < x+k; i++){
            vector<int> row;
            for(int j = y; j < y+k; j++)
                row.push_back(grid[i][j]);
            vec.push_back(row);
        }
        reverse(vec.begin(), vec.end());
        for(int i = x; i < x+k; i++){
            for(int j = y; j < y+k; j++)
                grid[i][j] = vec[i-x][j-y];
        }
        return grid;
    }
};
