class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), x;
        for(int i = 0; i < n; i++){
            x = mat[i][i];
            mat[i][i] = mat[i][n-1-i];
            mat[i][n-1-i] = x;
        }
        return ;
    }
};
