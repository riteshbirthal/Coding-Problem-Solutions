class Solution {
    public:
        int func(int n, int m, vector<int>& arr, unordered_map<int, int>& u, vector<vector<int>>& dp){
            if(u.find(arr[n]+arr[m])==u.end())
                return 0;
            if(dp[n][m]!=-1)
                return dp[n][m];
            return dp[n][m] = 1 + func(m, u[arr[n]+arr[m]], arr, u, dp);
        }
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size(), res = 0, f1, f2, f3;
            vector<vector<int>> dp(n, vector<int>(n, -1));
            unordered_map<int, int> u;
            for(int i = 0; i < n; i++)
                u[arr[i]] = i;
            for(int i = 0; i < n-2; i++){
                for(int j = i+1; j < n-1; j++){
                    dp[i][j] = func(i, j, arr, u, dp);
                    res = max(res, 2 + dp[i][j]);
                }
            }
            return res<3 ? 0 : res;
        }
    };