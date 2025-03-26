class Solution {
    public:
      vector<int> dx, dy;
      bool dfs(int x, int y, vector<vector<char>>& mat, int idx, string& word, vector<vector<int>>& visited){
          if(idx==word.size()-1)
              return true;
          bool res = false;
          visited[x][y] = 1;
          int n = mat.size(), m = mat[0].size();
          for(int i = 0; i < 4; i++){
              int X = x + dx[i], Y = y + dy[i];
              if(X>=0 && X<n && Y>=0 && Y<m && !visited[X][Y] && mat[X][Y] == word[idx+1]){
                  res = res || dfs(X, Y, mat, idx+1, word, visited);
              }
          }
          visited[x][y] = 0;
          return res;
      }
      bool isWordExist(vector<vector<char>>& mat, string& word) {
          // Code here
          bool res = false;
          int n = mat.size(), m = mat[0].size();
          vector<vector<int>> visited(n, vector<int>(m, 0));
          dx = {-1, 0, 0, 1};
          dy = {0, -1, 1, 0};
          for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++){
                  if(mat[i][j]==word[0]){
                      res = res || dfs(i, j, mat, 0, word, visited);
                  }
              }
          }
          return res;
      }
  };