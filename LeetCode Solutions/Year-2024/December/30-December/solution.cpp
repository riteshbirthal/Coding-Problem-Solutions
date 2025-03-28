class Solution {
    public:
        long long func(int len, int low, int high, int zero, int one, vector<long long>& dp){
            if(len>high){
                return 0;
            }
            if(dp[len]!=-1)
                return dp[len];
            long long ans = func(len+zero, low, high, zero, one, dp)%(long long)(1e9+7) + func(len+one, low, high, zero, one, dp)%(long long)(1e9+7);
            if(low<=len && len<=high){
                return dp[len] = 1 + ans;
            }
            return dp[len] = ans;
        }
        int countGoodStrings(int low, int high, int zero, int one) {
            vector<long long> dp(2*high+1, -1);
            return (int)func(0, low, high, zero, one, dp)%(int)(1e9+7);
        }
    };