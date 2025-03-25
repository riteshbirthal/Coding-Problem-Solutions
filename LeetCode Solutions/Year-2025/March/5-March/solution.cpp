class Solution {
    public:
        long long coloredCells(int n) {
            return 2*(long long)n*(long long)(n-1) + 1;
        }
    };