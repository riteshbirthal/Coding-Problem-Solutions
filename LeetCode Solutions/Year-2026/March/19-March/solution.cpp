class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<vector<int>>> vec(n, vector<vector<int>>(m, {0, 0}));
        if(grid[0][0]=='X') vec[0][0][0] = 1;
        if(grid[0][0]=='Y') vec[0][0][1] = 1;
        for(int i = 1; i < n; i++){
            vec[i][0] = vec[i-1][0];
            if(grid[i][0]=='X') vec[i][0][0] += 1;
            else if(grid[i][0]=='Y') vec[i][0][1] += 1;
            if(vec[i][0][0] && vec[i][0][0]==vec[i][0][1]) ans++;
        }
        for(int i = 1; i < m; i++){
            vec[0][i] = vec[0][i-1];
            if(grid[0][i]=='X') vec[0][i][0] += 1;
            else if(grid[0][i]=='Y') vec[0][i][1] += 1;
            if(vec[0][i][0] && vec[0][i][0]==vec[0][i][1]) ans++;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                vec[i][j] = {vec[i-1][j][0] + vec[i][j-1][0]-vec[i-1][j-1][0], vec[i-1][j][1] + vec[i][j-1][1]-vec[i-1][j-1][1]};
                if(grid[i][j]=='X'){
                    vec[i][j][0] += 1;
                }else if(grid[i][j]=='Y'){
                    vec[i][j][1] += 1;
                }
                if(vec[i][j][0] && vec[i][j][0]==vec[i][j][1]) ans++;
            }
        }
        return ans;
    }
};
