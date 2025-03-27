class Solution {
    public:
        int bfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited, map<vector<int>, vector<int>>& parent, map<vector<int>, int>& islandSize){
            vector<int> par = {x, y}, dx, dy, node;
            dx = {-1, 0, 0, 1};
            dy = {0, -1, 1, 0};
            visited[x][y] = 1;
            int n = grid.size(), m = grid[0].size(), X, Y, res = 0;
            queue<vector<int>> q;
            q.push({x, y});
            while(!q.empty()){
                node = q.front(), q.pop();
                x = node[0], y = node[1];
                parent[{x, y}] = par;
                for(int i = 0; i < 4; i++){
                    X = x + dx[i], Y = y + dy[i];
                    if(X>=0 && X<n && Y>=0 && Y<m && !visited[X][Y] && grid[X][Y]){
                        visited[X][Y] = 1;
                        q.push({X, Y});
                    }
                }
                res += 1;
            }
            return islandSize[par] = res;
        }
    
        bool check(int x, int y, int n, int m){
            return x>=0 && y>=0 && x<n && y<m;
        }
    
        int getMax(int x, int y, vector<vector<int>>& grid, map<vector<int>, vector<int>>& parent, map<vector<int>, int>& islandSize){
            int res = 0, x1, y1, n = grid.size(), m = grid[0].size();
            vector<int> dx, dy;
            dx = {-1, 0, 0, 1};
            dy = {0, -1, 1, 0};
            set<vector<int>> st;
            for(int i = 0; i < 4; i++){
                x1 = x + dx[i], y1 = y + dy[i];
                if(!check(x1, y1, n, m))
                    continue;
                if(grid[x1][y1])
                    st.insert(parent[{x1, y1}]);
            }
            for(auto itr = st.begin(); itr != st.end(); itr++)
                res += islandSize[*itr];
            return res;
        }
    
        int largestIsland(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size(), res = 0;
            vector<vector<int>> visited(n, vector<int>(m, 0));
            map<vector<int>, vector<int>> parent;
            map<vector<int>, int> islandSize;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] && !visited[i][j]){
                        res = max(res, bfs(i, j, grid, visited, parent, islandSize));
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(!visited[i][j]){
                        res = max(res, 1 + getMax(i, j, grid, parent, islandSize));
                    }
                }
            }
            return res;
        }
    };