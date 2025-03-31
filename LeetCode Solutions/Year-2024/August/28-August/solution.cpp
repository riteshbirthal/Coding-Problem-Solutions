class Solution {
public:
    vector<int> dx, dy;
    int bfs(vector<vector<int>>& g2, int x, int y, vector<vector<int>>& g1, vector<vector<int>>& v){
        int n = g1.size(), m = g1[0].size(), isSubIsland = 1, q_size;
        queue<vector<int>> q;
        q.push({x, y});
        v[x][y] = 1;
        vector<int> vec;
        while(!q.empty()){
            q_size = q.size();
            while(q_size--){
                vec = q.front(), x = vec[0], y = vec[1];
                q.pop();
                if(!g1[x][y])
                    isSubIsland = 0;
                for(int j = 0; j < 4; j++){
                    x = vec[0] + dx[j], y = vec[1] + dy[j];
                    if((x>=0 && x<n && y>=0 && y<m) && g2[x][y] && !v[x][y]){
                        q.push({x, y});
                        v[x][y] = 1;
                    }
                }
            }
        }
        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size(), ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        dx = {0, 0, 1, -1};
        dy = {1, -1, 0, 0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid2[i][j] && bfs(grid2, i, j, grid1, visited)){
                    ans++;
                }
            }
        }
        return ans;
    }
};