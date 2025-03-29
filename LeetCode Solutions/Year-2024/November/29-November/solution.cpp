class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vec(n, vector<int>(m, INT_MAX));
        vec[0][0] = 0;
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            int time = vec[x][y];
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int next_time;
                    if (grid[nx][ny] > time + 1) {
                        next_time = (grid[nx][ny] - time) % 2 == 1 ? grid[nx][ny] : grid[nx][ny] + 1;
                    } else {
                        next_time = time + 1;
                    }
                    if (next_time < vec[nx][ny]) {
                        vec[nx][ny] = next_time;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return vec[n-1][m-1];
    }
};
