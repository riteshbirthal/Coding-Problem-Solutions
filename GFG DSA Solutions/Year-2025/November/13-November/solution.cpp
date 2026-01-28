class Solution {
  public:
    int isInterleavePossible(string& s1, int n1, string& s2, int n2, string& s3, int n3, vector<vector<short int>>& dp){
        if(n1==0 && n2==0)
            return 1;
        if(dp[n1][n2]!=-1)
            return dp[n1][n2];
        int res = 0;
        if(n1 && s1[n1-1]==s3[n3-1])
            res = isInterleavePossible(s1, n1-1, s2, n2, s3, n3-1, dp);
        if(n2 && s2[n2-1]==s3[n3-1])
            res = res || isInterleavePossible(s1, n1, s2, n2-1, s3, n3-1, dp);
        return dp[n1][n2] = res;
    }
    
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1+n2!=n3)
            return true;
        vector<vector<short int>> dp(n1+1, vector<short int>(n2+1, -1));
        return isInterleavePossible(s1, n1, s2, n2, s3, n3, dp);
    }
};
