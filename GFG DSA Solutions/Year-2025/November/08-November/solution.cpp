class Solution {
  public:
    int getPaths(vector<vector<int>>& mat, int x, int y, int k, vector<vector<vector<int>>>& dp){
        int n = mat.size(), m = mat[0].size();
        if(x==n-1 && y==m-1)
            return k==mat[x][y] ? 1 : 0;
        if(k<0 || x==n || y==m)
            return 0;
        if(dp[k][x][y]!=-1)
            return dp[k][x][y];
        int res = getPaths(mat, x+1, y, k-mat[x][y], dp) + getPaths(mat, x, y+1, k-mat[x][y], dp);
        return dp[k][x][y] = res;
    }
    
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(n, vector<int>(m, -1)));
        return getPaths(mat, 0, 0, k, dp);
    }
};
