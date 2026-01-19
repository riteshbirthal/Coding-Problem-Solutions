class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int res = 0, left, right, mid, n = mat.size(), m = mat[0].size(), sum;
        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + mat[i][j];
                left = res, right = min(i, j) + 1;
                while(left<=right){
                    mid = (left + right) / 2;
                    sum = pref[i+1][j+1] - pref[i+1-mid][j+1] - pref[i+1][j+1-mid] + pref[i+1-mid][j+1-mid];
                    if(sum<=threshold)
                        left = mid + 1, res = mid;
                    else
                        right = mid - 1;
                }
            }
        }
        return res;
    }
};
