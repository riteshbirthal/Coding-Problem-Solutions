class Solution {
    public:
        int maxScoreSightseeingPair(vector<int>& values) {
            int n = values.size(), mx = values[0], ans = INT_MIN;
            for (int i = 1; i < n; i++) {
                ans = max(ans, values[i] - i + mx);
                mx = max(mx, values[i] + i);
            }
            return ans;
        }
    };