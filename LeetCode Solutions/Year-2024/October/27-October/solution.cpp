class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vec(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vec[i+1][j+1] = matrix[i][j] + vec[i][j+1] + vec[i+1][j] - vec[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k <= min(i, j); k++){
                    if(i>=k && j>=k && vec[i+1][j+1] - vec[i-k][j+1] - vec[i+1][j-k] + vec[i-k][j-k] == (k+1)*(k+1)){
                        count++;
                    }else{
                        break;
                    }
                }
            }
        }
        return count;
    }
};