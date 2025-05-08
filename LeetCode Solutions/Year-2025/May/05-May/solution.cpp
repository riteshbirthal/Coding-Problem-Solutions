class Solution {
public:
    int numTilings(int n) {
        if(n<3) return n;
        if(n==3) return 5;
        long long a = 1, b = 2, c = 5, ans;
        for(int i = 0; i < n-3; i++){
            ans = (2 * c + a) % (int(1e9 + 7));
            a = b, b = c, c = ans;
        }
        return ans;
    }
};