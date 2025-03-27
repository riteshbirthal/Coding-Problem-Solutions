class Solution {
    public:
        int countServers(vector<vector<int>>& grid) {
            int res = 0, n = grid.size(), m = grid[0].size();
            unordered_map<int, int> row, col;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j]){
                        row.find(i)==row.end() ? row[i] = 1 : row[i] += 1;
                        col.find(j)==col.end() ? col[j] = 1 : col[j] += 1;                }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j]){
                        (row[i]>1 || col[j]>1) ? res += 1 : res += 0;
                    }
                }
            }
            return res;
        }
    };