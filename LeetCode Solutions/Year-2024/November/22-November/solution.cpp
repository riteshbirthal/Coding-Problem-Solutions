class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ans = 0, count, n = matrix.size(), m = matrix[0].size(), sum;
        vector<int> v;
        for(int i = 0; i < n; i++){
            count = 0, v = matrix[i];
            for(int j = 0; j < n; j++){
                sum = 0;
                for(int k = 0; k < m; k++){
                    sum += (v[k]^matrix[j][k]);
                }
                if(sum==0 || sum==m) count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};