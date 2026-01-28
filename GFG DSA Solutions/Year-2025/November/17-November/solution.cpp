class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size(), res = 0, mx;
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; i++){
            mx = 0;
            for(int j = 0; j < i; j++){
                if(arr[i]>arr[j])
                    mx = max(mx, dp[j+1]);
            }
            dp[i+1] = mx + arr[i];
        }
        for(int i = 1; i <= n; i++)
            res = max(res, dp[i]);
        return res;
    }
};
