class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), ans = 0, a = 0, b = 0, c = 0, d = 0;
        if(n<5) return 0;
        sort(nums.begin(), nums.end());
        a = nums[n-1] - nums[3];
        b = nums[n-2] - nums[2];
        c = nums[n-3] - nums[1];
        d = nums[n-4] - nums[0];
        ans = min(a, min(b, min(c, d)));
        return ans;
    }
};