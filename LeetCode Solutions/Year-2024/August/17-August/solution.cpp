class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<vector<long long>> vec(n, vector<long long>(m, 0));
        vector<long long> left(m, INT_MIN), right(m, INT_MIN);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                vec[i][j] = points[i][j];
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                left[j] = max(left[j-1], vec[i-1][j-1]) - 1;
                right[m-j-1] = max(right[m-j], vec[i-1][m-j]) - 1;
            }
            for(int j = 0; j < m; j++){
                vec[i][j] += max(vec[i-1][j], max(left[j], right[j]));
            }
        }
        long long ans = INT_MIN;
        for(int i = 0; i < m; i++)
            ans = max(ans, vec[n-1][i]);
        return ans;
    }
};