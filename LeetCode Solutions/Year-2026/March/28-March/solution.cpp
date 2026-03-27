class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int x, n = mat.size(), m = mat[0].size();
        vector<vector<int>> updated = mat;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                updated[i][j] = i%2 ? mat[i][(j-k%m+m)%m] : mat[i][(j+k%m+m)%m];
            }
        }
        return updated==mat;
    }
};
