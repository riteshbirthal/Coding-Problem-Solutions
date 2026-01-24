class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size(), end = INT_MAX, count = 0, x = 0;
        long long res = 1, MOD = 1e9+7;
        for(int i = n-1; i >= 0; i--){
            count += corridor[i]=='S';
            if(count==2 && end==INT_MAX)
                end = i;
        }
        if(count%2 || end==INT_MAX)
            return 0;
        count = 0;
        for(int i = 0; i < end; i++){
            count += corridor[i]=='S';
            if(count && count%2==0)
                x += 1;
            if(count%2 && x){
                res = (res * x) % MOD;
                x = 0;
            }
        }
        cout << x << endl;
        if(x)
            res = (res * x) % MOD;
        return res;
    }
};
