class Solution {
public:
    int calculateSteps(int n, long curr, long next) {
        int steps = 0;
        while (curr <= n) {
            steps += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = calculateSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};