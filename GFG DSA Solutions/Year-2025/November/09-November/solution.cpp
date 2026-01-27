class Solution {
    int n;
  public:
    int getMaxChoc(vector<vector<int>>& mat, int x1, int y1, int x2, int y2, map<vector<int>, int>& dp){
        if(x1==n || y1==n || x2==n || y2==n || mat[x1][y1]==-1 || mat[x2][y2]==-1)
            return INT_MIN;
        if(x1==y1 && x2==y2 && x1==x2 && x1==n-1)
            return mat[x1][y1];
        vector<int> state{x1, y1, x2, y2};
        if(dp.find(state)!=dp.end())
            return dp[state];
        int res = max(getMaxChoc(mat, x1+1, y1, x2+1, y2, dp), 
                        max(getMaxChoc(mat, x1+1, y1, x2, y2+1, dp), 
                            max(getMaxChoc(mat, x1, y1+1, x2+1, y2, dp), getMaxChoc(mat, x1, y1+1, x2, y2+1, dp))));
        if(res!=INT_MIN){
            res += (x1==x2 && y1==y2) ? mat[x1][y1] : mat[x1][y1] + mat[x2][y2];
        }
        return dp[state] = res;
    }
    
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        n = mat.size();
        if(mat[n-1][n-1]==-1)
            return 0;
        map<vector<int>, int> dp;
        int res = getMaxChoc(mat, 0, 0, 0, 0, dp);
        return res==INT_MIN ? 0 : res;
    }
};
