class Solution {
    public:
        vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
            int n = isWater.size(), m = isWater[0].size(), height = 0, k;
            vector<int> cell, dx, dy;
            dx = {-1, 0, 0, 1};
            dy = {0, -1, 1, 0};
            queue<vector<int>> q;
            vector<vector<int>> res(n, vector<int>(m, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(isWater[i][j]) q.push({i, j}), isWater[i][j] = -1;
                }
            }
            while(q.size()){
                k = q.size();
                for(int i = 0; i < k; i++){
                    cell = q.front(), q.pop();
                    res[cell[0]][cell[1]] = height;
                    for(int j = 0; j < 4; j++){
                        int x = cell[0] + dx[j], y = cell[1] + dy[j];
                        if(x>=0 && x<n && y>=0 && y<m && isWater[x][y]!=-1){
                            isWater[x][y] = -1;
                            q.push({x, y});
                        }
                    }
                }
                height += 1;
            }
            return res;
        }
    };