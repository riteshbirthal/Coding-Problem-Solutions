class Solution {
public:
    int binaryGap(int n) {
        int res = 0, count = -50;
        while (n) {
            if (n & 1)
                res = max(res, count), count = 0;
            count++;
            n /= 2;
        }
        return res;
    }
};
