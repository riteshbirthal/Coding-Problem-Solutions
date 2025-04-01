class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0, ans2 = 0;
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        for(int i = n-k; i < n; i++){
            ans += max(0, happiness[i] - (i - n + k));
        }
        for(int i = n-1; i > max(-1, n-k-1); i--){
            ans2 += max(0, happiness[i] - (n - 1 - i));
        }
        ans = max(ans, ans2);
        return ans;
    }
};