class Solution {           
public:
    int rhombusElementSum(vector<vector<vector<int>>>& dp, int x, int y, int len){
        int res = 0, n = dp.size(), m = dp[0].size();
        if(len==0)
            return dp[x+1][y+1][0]-dp[x][y][0];
        if(x+1+2*len>n-2 || y+1-len<1 || y+1+len>m-2)
            return res;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        x1 = dp[x+1][y+1][0], y1 = dp[x+1][y+1][1];
        x2 = dp[x+1+len][y+1-len][0], y2 = dp[x+1+len][y+1-len][1];
        x3 = dp[x+1+2*len][y+1][0], y3 = dp[x+1+2*len][y+1][1];
        x4 = dp[x+1+len][y+1+len][0], y4 = dp[x+1+len][y+1+len][1];
        res += x4-x1 + x3-x2 + y3-y4 + y2-y1;
        int e1, e2, e3, e4;
        e1 = dp[x+1][y+1][0] - dp[x][y][0];
        e2 = dp[x+1+len][y+1-len][0] - dp[x+len][y-len][0];
        e3 = dp[x+1+2*len][y+1][0] - dp[x+2*len][y][0];
        e4 = dp[x+1+len][y+1+len][0] - dp[x+len][y+len][0];
        res += e1 - e3;
        return res;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(m+2, vector<int>(2, 0)));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i+1][j+1][0] = grid[i][j] + dp[i][j][0];
                dp[i+1][j+1][1] = grid[i][j] + dp[i][j+2][1];
            }
        }
        set<int> areas;
        int rhSize;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rhSize = min(j, min(m-1-j, (n-i+1)/2));
                for(int k = 0; k < rhSize+1; k++){
                    areas.insert(rhombusElementSum(dp, i, j, k));
                }
            }
        }

        vector<int> res;
        int count = 0;
        for(auto x = areas.rbegin(); x != areas.rend() && count < 3 && *x>0; x++, count++)
            res.push_back(*x);
        return res;
    }
};
