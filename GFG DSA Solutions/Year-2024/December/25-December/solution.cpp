// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int n = mat.size(), m = mat[0].size(), c0 = 1;
        if(mat[0][0]==0) c0 = 0;
        for(int i = 1; i < n; i++)
            if(mat[i][0]==0) c0 = 0;
        for(int i = 1; i < m; i++)
            if(mat[0][i]==0) mat[0][0] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j]==0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++){
            if(mat[i][0]!=0)
                continue;
            for(int j = 1; j < m; j++)
                mat[i][j] = 0;
        }
        for(int i = 1; i < m; i++){
            if(mat[0][i]!=0)
                continue;
            for(int j = 1; j < n; j++)
                mat[j][i] = 0;
        }
        if(mat[0][0]==0 && c0==0){
            for(int i = 0; i < n; i++)
                mat[i][0] = 0;
            for(int i = 0; i < m; i++)
                mat[0][i] = 0;
        }else if(mat[0][0]==0){
            for(int i = 0; i < m; i++)
                mat[0][i] = 0;
        }else if(c0==0){
            for(int i = 0; i < n; i++)
                mat[i][0] = 0;
        }
        return ;
    }
};