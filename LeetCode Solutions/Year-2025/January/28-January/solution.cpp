class Solution {
    public:
        int func(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited){
            visited[x][y] = 1;
            int res = 0, X, Y, n = grid.size(), m = grid[0].size();
            queue<vector<int>> q;
            vector<int> v, dx, dy;
            dx = {-1, 0, 0, 1};
            dy = {0, -1, 1, 0};
            q.push({x, y});
            while(!q.empty()){
                v = q.front(), q.pop();
                x = v[0], y = v[1];
                res += grid[x][y];
                for(int j = 0; j < 4; j++){
                    X = x + dx[j], Y = y + dy[j];
                    if(X>=0 && X<n && Y>=0 && Y<m && grid[X][Y] && !visited[X][Y]){
                        visited[X][Y] = 1;
                        q.push({X, Y});
                    }
                }
            }
            return res;
        }
    
        int findMaxFish(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size(), res = 0;
            vector<vector<int>> visited(n, vector<int>(m, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j]==0)
                        visited[i][j] = 1;
                    if(grid[i][j] && !visited[i][j]){
                        res = max(res, func(i, j, grid, visited));
                    }
                }
            }
            return res;
        }
    };