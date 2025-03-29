class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size(), idx_l, idx_u;
        for(int i = 0; i < n-1; i++){
            idx_l = lower_bound(nums.begin()+i+1, nums.end(), lower - nums[i]) - nums.begin();
            idx_u = upper_bound(nums.begin()+i+1, nums.end(), upper - nums[i]) - nums.begin()-1;
            if(idx_l<n && idx_l<=idx_u)
                ans += idx_u - idx_l + 1;
        }
        return ans;
    }
};