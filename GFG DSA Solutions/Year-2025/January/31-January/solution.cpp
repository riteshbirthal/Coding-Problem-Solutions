class Solution {
    public:
      bool func(vector<vector<int>>& board, vector<vector<int>>& vec, int n, vector<set<int>>& row, vector<set<int>> &column, vector<set<int>> & box){
          if(n==vec.size()) return true;
          int x = vec[n][0], y = vec[n][1], flag = 0;
          for(int i = 0; i < 9; i++){
              if(row[x].find(i+1)==row[x].end() && column[y].find(i+1)==column[y].end() && box[3*(x/3) + y/3].find(i+1)==box[3*(x/3) + y/3].end()){
                  row[x].insert(i+1), column[y].insert(i+1), box[3*(x/3) + y/3].insert(i+1);
                  flag = flag | func(board, vec, n+1, row, column, box);
                  if(flag){
                      board[x][y] = i + 1;
                      return true;
                  }
                  row[x].erase(i+1), column[y].erase(i+1), box[3*(x/3) + y/3].erase(i+1);
              }
          }
          return false;
      }
      // Function to find a solved Sudoku.
      void solveSudoku(vector<vector<int>> &mat) {
          // code here
          vector<set<int>> row(9), column(9), box(9);
          vector<vector<int>> vec;
          for(int i = 0; i < 9; i++)
              for(int j = 0; j < 9; j++)
                  if(mat[i][j]==0) vec.push_back({i,j});
                  else row[i].insert(mat[i][j]), column[j].insert(mat[i][j]), box[3*(i/3) + (j/3)].insert(mat[i][j]);
          func(mat, vec, 0, row, column, box);
          return ;
      }
  };