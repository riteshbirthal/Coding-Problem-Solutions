class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size(), mx;
        vector<vector<int>> vec(n-2, vector<int>(n-2, 0));
        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < n-2; j++){
                mx = 0;
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        mx = max(mx, grid[i+k][j+l]);
                    }
                }
                vec[i][j] = mx;
            }
        }
        return vec;
    }
};