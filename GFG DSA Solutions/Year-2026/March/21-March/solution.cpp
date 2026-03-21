class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        vector<int> dp(7, 1);
        for(int i = 2; i < 7; i++){
            int tot = 0;
            for(int j = 0; j < i; j++){
                tot += dp[j] * dp[i-j-1];
            }
            dp[i] = tot;
        }
        vector<int> temp = arr, res;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> u;
        int n = arr.size();
        for(int i = 0; i < n; i++)
            u[temp[i]] = i;
        for(int x : arr){
            res.push_back(dp[u[x]] * dp[n-1-u[x]]);
        }
        return res;
    }
};
