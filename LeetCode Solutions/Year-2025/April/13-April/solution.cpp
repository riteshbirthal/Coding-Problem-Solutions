class Solution {
    public:
        int countGoodNumbers(long long n) {
            if(n==0)
                return 1;
            long long res = (n/2)%2 ? countGoodNumbers((n-2)/2) : countGoodNumbers(n/2), mod = 1e9 + 7;
            res *= res;
            res %= mod;
            if((n/2)%2)
                res *= 20;
            res %= mod;
            if(n%2)
                res *= 5;
            return (int)(res%mod);
        }
    };