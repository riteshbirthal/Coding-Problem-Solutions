class Solution {
    public:
        long long modInverse(long long a, long long m) {
            long long res = 1, b = m - 2;
            while (b) {
                if (b & 1) res = (res * a) % m;
                a = (a * a) % m;
                b >>= 1;
            }
            return res;
        }
    
        vector<long long> computeNCm(int n, long long mod) {
            vector<long long> nCm(n, 1);
            for (int i = 1; i < n; i++) {
                nCm[i] = (nCm[i-1] * (n - i) % mod * modInverse(i, mod)) % mod;
            }
            return nCm;
        }
    
        int countArr(int preEle, int n, int size, int maxVal, vector<long long>& nCm){
            if(preEle>maxVal || n>size)
                return 0;
            long long res = nCm[n-1],  mod = 1e9 + 7;
            for(int i = 2; preEle*i <= maxVal; i++){
                res += countArr(preEle*i, n+1, size, maxVal, nCm);
                res %= mod;
            }
            return (int)res;
        }
    
        int idealArrays(int n, int maxValue) {
            long long res = 0, mod = 1e9+7;
            vector<long long> nCm = computeNCm(n, mod);
            
            for(int i = 1; i <= maxValue; i++){
                res += countArr(i, 1, n, maxValue, nCm);
                res %= mod;
            }
            return (int)res;
        }
    };