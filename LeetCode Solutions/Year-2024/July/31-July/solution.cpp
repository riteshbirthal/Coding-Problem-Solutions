class Solution {
public:
    int func(vector<vector<int>>& books, int sw, int n, vector<int>& dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX, mx = INT_MIN, width = 0;
        for(int i = n; i >= 0; i--){
            width += books[i][0];
            mx = max(mx, books[i][1]);
            if(width<=sw){
                ans = min(ans, mx + func(books, sw, i-1, dp));
            }else{
                break;
            }
        }
        return dp[n] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n, -1);
        return func(books, shelfWidth, n-1, dp);
    }
};