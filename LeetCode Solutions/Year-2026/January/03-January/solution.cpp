class Solution {
    vector<string> vec;
    unordered_map<string, int> mapping;
    long long MOD = 1e9 + 7;
public:
    long long getWays(int n, int m, vector<vector<long long>>& dp){
        if(n==0)
            return 1;
        if(dp[n][m]!=-1)
            return dp[n][m];
        long long res = 0;
        for(int i = 1; i < 13; i++){
            if((vec[m][0]!=vec[i][0]) && (vec[m][1]!=vec[i][1]) && (vec[m][2]!=vec[i][2]))
                res = (res + getWays(n-1, i, dp)) % MOD;
        }
        return dp[n][m] = res;
    }

    int numOfWays(int n) {
        vec = {"xxx", "010", "012", "020", "021", "101", "102", "120", "121", "201", "202", "210", "212"};
        vector<vector<long long>> dp(n+1, vector<long long>(13, -1));
        for(int i = 0; i < 12; i++)
            mapping[vec[i]] = i;
        return getWays(n, 0, dp);
    }
};
