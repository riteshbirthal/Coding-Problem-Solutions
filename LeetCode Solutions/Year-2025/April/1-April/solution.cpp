class Solution {
public:
    long long getMaxPoints(vector<vector<int>>& questions, int n, vector<long long>& dp){
        if(n>=questions.size())
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        long long res = getMaxPoints(questions, n + 1, dp);
        res = max(res, getMaxPoints(questions, n + 1 + questions[n][1], dp) + questions[n][0]);
        return dp[n] = res;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return getMaxPoints(questions, 0, dp);
    }
};