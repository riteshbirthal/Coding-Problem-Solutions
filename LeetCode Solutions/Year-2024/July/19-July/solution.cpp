class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ans, row(n, INT_MAX), column(m,INT_MIN);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                row[i] = min(row[i], matrix[i][j]);
                column[j] = max(column[j], matrix[i][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]==row[i] && matrix[i][j]==column[j])
                    ans.push_back(row[i]);
            }
        }
        return ans;
    }
};