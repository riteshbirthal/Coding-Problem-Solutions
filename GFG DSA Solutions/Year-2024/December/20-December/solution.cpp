class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> vec;
        for(int i = 0; i < min(n+1, m+1)/2; i++){
            // East
            for(int j = i; j <= m-1-i; j++){
                if(mat[i][j]!=INT_MAX)
                    vec.push_back(mat[i][j]);
                mat[i][j] = INT_MAX;
            }
            // South
            for(int j = i+1; j <= n-1-i; j++){
                if(mat[j][m-1-i]!=INT_MAX)
                    vec.push_back(mat[j][m-1-i]);
                mat[j][m-1-i] = INT_MAX;
            }
            // West
            for(int j = m-2-i; j>=i; j--){
                if(mat[n-1-i][j]!=INT_MAX)
                    vec.push_back(mat[n-1-i][j]);
                mat[n-1-i][j] = INT_MAX;
            }
            // North
            for(int j = n-2-i; j>i; j--){
                if(mat[j][i]!=INT_MAX)
                    vec.push_back(mat[j][i]);
                mat[j][i] = INT_MAX;
            }
        }
        return vec;
        
    }
};