class Solution {
public:
    void mark(int x, int y, vector<vector<int>>& land, vector<vector<int>>& ans, vector<vector<int>>& visited){
        int n = land.size(), m = land[0].size();
        for(int i = x; i < n; i++)
            if(land[i][y]==0) n = i;
        for(int i = y; i < m; i++)
            if(land[x][i]==0) m = i;
        for(int i = x; i < n; i++){
            for(int j = y; j < m; j++){
                visited[i][j] = 1;
            }
        }
        ans.push_back({x, y, n-1, m-1});
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0)), ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] && !visited[i][j]){
                    mark(i, j, land, ans, visited);
                }
            }
        }
        return ans;
    }
};