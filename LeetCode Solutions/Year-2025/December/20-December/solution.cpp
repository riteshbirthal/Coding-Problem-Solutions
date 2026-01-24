class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, n = strs.size(), m = strs[0].size();
        bool isSorted;
        for(int i = 0; i < m; i++){
            isSorted = true;
            for(int j = 1; j < n && isSorted; j++)
                isSorted = strs[j-1][i]<=strs[j][i];
            res += !isSorted;
        }
        return res;
    }
};
