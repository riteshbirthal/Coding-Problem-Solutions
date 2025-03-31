class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0, num = start^goal;
        while(num){
            ans += num&1==1 ? 1 : 0;
            num = num>>1;
        }
        return ans;
    }
};