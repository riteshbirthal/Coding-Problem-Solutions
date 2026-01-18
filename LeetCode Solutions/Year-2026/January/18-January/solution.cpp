class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int res = 1, n = grid.size(), m = grid[0].size(), target_sum, curr_sum, mgs_size;
        vector<vector<pair<int, int>>> pref(n+1, vector<pair<int, int>>(m+1, {0, 0}));
        bool is_mag;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pref[i+1][j+1] = {grid[i][j] + pref[i][j+1].first, grid[i][j] + pref[i+1][j].second};
                mgs_size = min(i, j) + 1;
                for(int k = res+1; k <= mgs_size; k++){
                    is_mag = true;
                    target_sum = pref[i+1][j+1].first - pref[i-k+1][j+1].first;
                    for(int l = i+1; l > i+1-k && is_mag; l--)
                        is_mag = is_mag && ((pref[l][j+1].second - pref[l][j+1-k].second)==target_sum);
                    for(int l = j+1; l > j+1-k && is_mag; l--)
                        is_mag = is_mag && ((pref[i+1][l].first - pref[i+1-k][l].first)==target_sum);
                    curr_sum = 0;
                    for(int l = 0; l < k && is_mag; l++)
                        curr_sum += grid[i-l][j-l];
                    is_mag = is_mag && curr_sum==target_sum;
                    curr_sum = 0;
                    for(int l = 0; l < k && is_mag; l++)
                        curr_sum += grid[i-l][j-k+1+l];
                    is_mag = is_mag && curr_sum==target_sum;
                    if(is_mag)
                        res = k;
                }
            }
        }
        return res;
    }
};
