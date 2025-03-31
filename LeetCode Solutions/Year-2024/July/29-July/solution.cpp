class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ans = 0;
        vector<vector<int>> vec(n + 1, {0, 0});
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rating[i] < rating[j])
                    vec[i][0]++;
                else
                    vec[i][1]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rating[i] < rating[j])
                    ans += vec[j][0];
                else
                    ans += vec[j][1];
            }
        }
        return ans;
    }
};