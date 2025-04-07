class Solution {
public:
    bool func(vector<int>& nums, int n, int target, vector<vector<int>>& vec){
        if(target==0) return true;
        if(n<0 || target<0) return false;
        if(vec[n][target]!=-1) return vec[n][target];
        return vec[n][target] = func(nums, n-1, target, vec) || func(nums, n-1, target-nums[n], vec);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto x : nums)
            sum += x;
        if(sum%2)
            return false;
        vector<vector<int>> vec(n, vector<int>(sum/2 + 1, -1));
        return func(nums, n-1, sum/2, vec);
    }
};
