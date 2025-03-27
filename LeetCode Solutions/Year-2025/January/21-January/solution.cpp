class Solution {
    public:
        long long gridGame(vector<vector<int>>& grid) {
            int n = grid[0].size();
            long long res = LONG_MAX;
            vector<long long> left2(n+1, 0), right1(n+1, 0);
            for(int i = 0; i < n; i++){
                left2[i+1] = left2[i] + grid[1][i];
                right1[n-1-i] = right1[n-i] + grid[0][n-1-i];
            }
            for(int i = 0; i < n; i++){
                long long a = right1[i+1], b = left2[i];
                res = min(res, max(a, b));
            }
            return res;
        }
    };