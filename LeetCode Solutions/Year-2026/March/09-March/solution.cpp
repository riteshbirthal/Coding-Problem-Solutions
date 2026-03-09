class Solution {
    long long MOD = 1e9 + 7;
    int lmt, dp[201][201][201][2];
public:
    int findStableArr(int zero, int one, int limit, int lastDigit){
        if(limit<0)
            return 0;
        if(zero==0 && one==0)
            return 1;
        if(dp[zero][one][limit][lastDigit]!=-1)
            return dp[zero][one][limit][lastDigit];
        long long res = 0;
        if(zero){
            if(lastDigit){
                res += findStableArr(zero-1, one, lmt-1, 0);
            }else{
                res += findStableArr(zero-1, one, limit-1, 0);
            }
        }
        if(one){
            if(lastDigit){
                res += findStableArr(zero, one-1, limit-1, 1);
            }else{
                res += findStableArr(zero, one-1, lmt-1, 1);
            }
        }
        res %= MOD;
        return dp[zero][one][limit][lastDigit] = res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        for(int i = 0; i < zero+1; i++)
            for(int j = 0; j < one+1; j++)
                for(int k = 0; k < limit+1; k++)
                    dp[i][j][k][0] = dp[i][j][k][1] = -1;
        lmt = limit;
        int res = (long long)(findStableArr(zero-1, one, limit-1, 0) + findStableArr(zero, one-1, limit-1, 1)) % MOD;
        return res;
    }
};
