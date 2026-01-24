class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long res = n>0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] == prices[i] + 1)
                dp[i] = dp[i - 1] + 1;
            res += dp[i];
        }
        return res;
    }
};
