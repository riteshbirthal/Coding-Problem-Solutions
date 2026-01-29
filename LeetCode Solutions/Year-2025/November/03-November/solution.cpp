class Solution {
public:
    int getMinCost(string& colors, vector<int>& neededTime, int n, int ch, vector<vector<int>>& dp){
        if(n<0)
            return 0;
        if(dp[ch][n]!=-1)
            return dp[ch][n];
        int res = neededTime[n] + getMinCost(colors, neededTime, n-1, ch, dp);
        if(ch!=colors[n]-'a'){
            res = min(res, getMinCost(colors, neededTime, n-1, colors[n]-'a', dp));
        }
        return dp[ch][n] = res;
    }

    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), res;
        vector<vector<int>> dp(27, vector<int>(n, -1));
        res = getMinCost(colors, neededTime, n-1, 26, dp);
        return res;
    }
};
