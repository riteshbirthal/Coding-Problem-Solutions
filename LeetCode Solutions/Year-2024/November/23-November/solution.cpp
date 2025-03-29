class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size(), idx;
        vector<vector<char>> vec(m, vector<char>(n, '.'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vec[j][n-1-i] = box[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = m-1; j >= 0; j--){
                if(vec[j][i]=='#'){
                    idx = m;
                    for(int k = j+1; k < m && idx==m; k++){
                        if(vec[k][i]=='#' || vec[k][i]=='*') idx = k;
                    }
                    vec[j][i] = '.';
                    vec[idx-1][i] = '#';
                }
            }
        }
        return vec;
    }
};