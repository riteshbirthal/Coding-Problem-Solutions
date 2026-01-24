class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int left = 0, right = nums.size()-1, res = 0;
        sort(nums.begin(), nums.end());
        while(left<right)
            res = max(res, nums[left++]+nums[right--]);
        return res;
    }
};
