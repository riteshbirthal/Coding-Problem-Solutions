class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), isZeros = 0, count = 0, mx = INT_MIN, mn = INT_MAX;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j]==0) isZeros++;
                else if(matrix[i][j]<0) count++, mx = max(mx, matrix[i][j]);
                else mn = min(mn, matrix[i][j]);
                sum += abs(matrix[i][j]);
            }
        }
        if(count%2){
            sum = isZeros ? sum : (mx==INT_MIN ? sum : sum - 2*min(abs(mx), mn));
        }
        return sum;
    }
};
