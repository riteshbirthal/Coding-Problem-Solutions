//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<int> dx, dy;
  public:
    void visitIsland(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){
        visited[x][y] = true;
        for(int i = 0; i < 8; i++){
            int X = x + dx[i], Y = y + dy[i];
            if(X>=0 && Y>=0 && X<grid.size() && Y<grid[0].size() && grid[X][Y]=='L' && !visited[X][Y])
                visitIsland(grid, X, Y, visited);
        }
        return ;
    }
    
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]=='L' && !visited[i][j]){
                    visitIsland(grid, i, j, visited);
                    res += 1;
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
