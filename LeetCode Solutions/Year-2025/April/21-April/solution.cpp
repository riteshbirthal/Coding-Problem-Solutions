class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int res = 0;
        long long mn = 0, mx = 0, sum = 0;
        for(int & d : differences){
            sum += (long long)d;
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        res = max((long long)0, (long long)(upper - lower + 1) - mx + mn);
        return res;
    }
};