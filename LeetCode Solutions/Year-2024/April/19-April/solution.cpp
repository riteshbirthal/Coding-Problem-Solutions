class Solution {
public:
    void func(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& visit){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return ;
        if(grid[i][j]=='0' || visit[i][j]) return ;
        visit[i][j] = 1;
        func(grid, i+1, j, visit);
        func(grid, i-1, j, visit);
        func(grid, i, j+1, visit);
        func(grid, i, j-1, visit);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]=='1' && visit[i][j]==0){
                    ans += 1;
                    func(grid, i, j, visit);
                }
            }
        }
        return ans;
    }
};