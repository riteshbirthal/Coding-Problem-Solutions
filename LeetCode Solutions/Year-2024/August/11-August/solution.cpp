class Solution {
public:
    vector<int> dx, dy;
    bool check(int x, int y, int n, int m){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y, int n, int m){
        visited[x][y] = 1;
        queue<pair<int, int>> q;
        q.push({x, y});
        int k;
        while(!q.empty()){
            k = q.size();
            for(int i = 0; i < k; i++){
                auto [x, y] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    if(check(x+dx[j], y+dy[j], n, m) && grid[x+dx[j]][y+dy[j]] && !visited[x+dx[j]][y+dy[j]])
                        visited[x+dx[j]][y+dy[j]] = 1, q.push({x+dx[j], y+dy[j]});
                }
            }
        }
        return ;
    }
    int count_islands(vector<vector<int>>& grid, vector<vector<int>> visited){
        int count = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] && !visited[i][j]){
                    bfs(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 2, islands;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
        islands = count_islands(grid, visited);
        if(islands!=1)
            return 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    visited[i][j] = 1;
                    islands = count_islands(grid, visited);
                    visited[i][j] = 0;
                    if(islands!=1)
                        return 1;
                }
            }
        }
        return 2;
    }
};