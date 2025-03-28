class Solution {
    public:
        int numWays(vector<string>& words, string target) {
            int n = target.size(), m = words[0].size();
            vector<vector<long>> dp(n+1, vector<long>(m+1, -1));
            return (int)func(words, target, 0, 0, dp);
        }
        long func(vector<string>& words, string &target, int n, int m, vector<vector<long>>& dp){
            if(dp[n][m]!=-1) return dp[n][m];
            if(n==target.size()) return 1;
            if(m==words[0].size() || (words[0].size() - m < target.size() - n)) return 0;
            long ans = 0;
            for(int i = 0; i<words.size(); i++){
                if(target[n]==words[i][m]){
                    ans += func(words, target, n+1, m+1, dp)%long(1e9+7);
                }
            }
            ans += func(words, target, n, m+1, dp)%long(1e9+7);
            return dp[n][m] = ans%long(1e9+7);
        }
    };