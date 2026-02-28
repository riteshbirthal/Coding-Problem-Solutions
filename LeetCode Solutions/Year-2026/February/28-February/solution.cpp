class Solution {
    long long MOD = 1e9+7;
public:
    string numToBinaryString(long long n){
        string res = "";
        long long temp = n;
        while(n){
            res += n&1 ? '1' : '0';
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    long long binaryStringToNum(string st){
        long long res = 0;
        for(char c : st){
            res = (long long)2*res + c-'0';
            res %= MOD;
        }
        return res;
    }

    int concatenatedBinary(int n) {
        long long res = 0;
        string resStr = "";
        for(int i = 1; i <= n; i++){
            resStr += numToBinaryString((long long)i);
            if(resStr.size()>1000)
                res = binaryStringToNum(resStr), resStr = numToBinaryString(res);
        }
        res = binaryStringToNum(resStr);
        return res;
    }
};
