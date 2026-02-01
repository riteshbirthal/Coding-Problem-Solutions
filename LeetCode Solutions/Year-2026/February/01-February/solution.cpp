class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        sort(nums.begin(), nums.end());
        if(nums[2]>first)
            return nums[0]+nums[1]+nums[2];
        return nums[0] + nums[1] + first;
    }
};
