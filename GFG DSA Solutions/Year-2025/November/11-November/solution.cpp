class Solution {
  public:
    int getLCS(string& s1, int n1, string& s2, int n2, vector<vector<int>>& dp){
        if(n1<0 || n2<0)
            return 0;
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
        int res = 0;
        res = max(res, getLCS(s1, n1-1, s2, n2, dp));
        res = max(res, getLCS(s1, n1, s2, n2-1, dp));
        if(s1[n1]==s2[n2])
            res = max(res, 1+getLCS(s1, n1-1, s2, n2-1, dp));
        return dp[n1][n2] = res;
    }
    
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n1= s1.size(), n2 = s2.size(), res;
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        res = n1 + n2 - getLCS(s1, n1-1, s2, n2-1, dp);
        return res;
    }
};
