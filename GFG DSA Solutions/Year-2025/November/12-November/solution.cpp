class Solution {
  public:
    int isWildCard(string &txt, int n, string &pat, int m, vector<vector<int>>& dp){
        if(n==-1 && m==-1)
            return 1;
        if(n==-1 || m==-1)
            return n==-1 ? (pat[m]=='*' ? isWildCard(txt, n, pat, m-1, dp) : 0) : 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        int res = 0;
        if(txt[n]==pat[m] || pat[m]=='?')
            res = isWildCard(txt, n-1, pat, m-1, dp);
        else if(pat[m]=='*')
            res = isWildCard(txt, n-1, pat, m-1, dp) || isWildCard(txt, n-1, pat, m, dp) || isWildCard(txt, n, pat, m-1, dp);
        return dp[n][m] = res;
    }
    
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size(), m = pat.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return isWildCard(txt, n-1, pat, m-1, dp);
    }
};
