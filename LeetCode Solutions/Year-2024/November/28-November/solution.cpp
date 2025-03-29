class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), k, obstacles, x, y;
        vector<vector<int>> vec(n, vector<int>(m, INT_MAX));
        vec[0][0] = grid[0][0];
        queue<vector<int>> q;
        q.push({0, 0});
        vector<int> v, dx, dy;
        dx = {-1, 0, 0, 1};
        dy = {0, -1, 1, 0};
        while(q.size()){
            k = q.size();
            for(int i = 0; i < k; i++){
                v = q.front(), q.pop();
                for(int j = 0; j < 4; j++){
                    x = v[0] + dx[j], y = v[1] + dy[j];
                    if(x>=0 && x<n && y>=0 && y<m && vec[x][y]>vec[v[0]][v[1]]+grid[v[0]][v[1]]){
                        vec[x][y] = vec[v[0]][v[1]]+grid[v[0]][v[1]];
                        q.push({x, y});
                    }
                }
            }
        }
        return vec[n-1][m-1];
    }
};