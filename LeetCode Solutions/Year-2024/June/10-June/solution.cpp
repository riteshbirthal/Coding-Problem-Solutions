class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0, n = heights.size();
        vector<int> vec = heights;
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n; i++) if(vec[i]!=heights[i]) ans++;
        return ans;
    }
};