
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>> vec = mat;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mat[n-1-j][i] = vec[i][j];
            }
        }
        return ;
    }
};
