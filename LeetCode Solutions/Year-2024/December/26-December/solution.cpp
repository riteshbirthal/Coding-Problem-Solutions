class Solution {
    public:
        int func(vector<int>& nums, int target, int n, unordered_map<string, int>& dp){
            if(n==0) return target==0;
            string key = to_string(target) + " " + to_string(n);
            if(dp.find(key)!=dp.end()) return dp[key];
            int ans = func(nums, target+nums[n-1], n-1, dp) + func(nums, target-nums[n-1], n-1, dp);
            return dp[key] = ans;
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            int n = nums.size();
            unordered_map<string, int> dp;
            return func(nums, target, n, dp);
        }
    };