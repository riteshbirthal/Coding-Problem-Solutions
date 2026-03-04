class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> row(n, 0), column(m, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                row[i] += mat[i][j], column[j] += mat[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res += (mat[i][j] && row[i]==1 && column[j]==1);
        return res;    
    }
};
