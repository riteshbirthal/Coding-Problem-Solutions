class Solution {
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> vec(n, vector<int>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                vec[j][n-1-i] = mat[i][j];
        return vec;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool res = mat==target;
        for(int i = 0; i < 3 && !res; i++){
            mat = rotateMatrix(mat);
            res = mat==target;
        }
        return res;
    }
};
