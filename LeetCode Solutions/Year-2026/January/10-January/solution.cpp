class Solution {
public:
    int getMinDel(string& s1, int n1, string& s2, int n2, vector<vector<int>>& dp){
        if(n1<0 && n2<0)
            return 0;
        if(n1<0)
            return s2[n2] + getMinDel(s1, n1, s2, n2-1, dp);
        if(n2<0)
            return s1[n1] + getMinDel(s1, n1-1, s2, n2, dp);
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
        if(s1[n1]==s2[n2])
            return dp[n1][n2] = getMinDel(s1, n1-1, s2, n2-1, dp);
        return dp[n1][n2] = min(s1[n1] + getMinDel(s1, n1-1, s2, n2, dp), s2[n2] + getMinDel(s1, n1, s2, n2-1, dp));
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return getMinDel(s1, n1-1, s2, n2-1, dp);
    }
};
