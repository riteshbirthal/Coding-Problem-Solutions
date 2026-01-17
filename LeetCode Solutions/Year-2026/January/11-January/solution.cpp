class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size(), left, right;
        vector<vector<vector<int>>> vec(n, vector<vector<int>>(m, vector<int>(2, 0)));
        vec[0][0][0] = matrix[0][0]-'0', vec[0][0][1] = matrix[0][0]-'0';
        ans = max(vec[0][0][0], vec[0][0][1]);
        for(int i = 1; i < n; i++){
            if(matrix[i][0]-'0'){
                vec[i][0][0] = vec[i-1][0][0] + 1;
                vec[i][0][1] = 1;
                ans = max(ans, vec[i][0][0]);
            }
        }
        for(int j = 1; j < m; j++){
            if(matrix[0][j]-'0'){
                vec[0][j][0] = 1;
                vec[0][j][1] = vec[0][j-1][1] + 1;
                ans = max(ans, vec[0][j][1]);
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j]=='1'){
                    vec[i][j][0] = vec[i-1][j][0] + 1;
                    vec[i][j][1] = vec[i][j-1][1] + 1;
                    left = vec[i][j][1];
                    for(int k = i; k >= 0; k--){
                        left = min(left, vec[k][j][1]);
                        if(matrix[k][j]) ans = max(ans, left * (i-k+1));
                        else break;
                    }
                    right = vec[i][j][0];
                    for(int k = j; k >= 0; k--){
                        right = min(right, vec[i][k][0]);
                        if(matrix[i][k]) ans = max(ans, right * (j-k+1));
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};
