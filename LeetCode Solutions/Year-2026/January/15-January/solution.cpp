class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int res = 0, hn = hBars.size(), vn = vBars.size(), dh = 1, dv = 1, curr_diff = 1;
        for(int i = 1; i < hn; i++)
            hBars[i]==hBars[i-1]+1 ? (curr_diff++, dh = max(dh, curr_diff)) : curr_diff = 1;
        curr_diff = 1;
        for(int i = 1; i < vn; i++)
            vBars[i]==vBars[i-1]+1 ? (curr_diff++, dv = max(dv, curr_diff)) : curr_diff = 1;
        res = (min(dh, dv) + 1) * (min(dh, dv) + 1);
        return res;
    }
};
