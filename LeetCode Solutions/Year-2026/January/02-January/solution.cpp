class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if(nums[0]==nums[1])
            return nums[0];
        int n = nums.size() / 2;
        for(int i = 1; i < n; i++){
            if(nums[2*i]==nums[2*i-1] || nums[2*i]==nums[2*i-2])
                return nums[2*i];
            else if(nums[2*i+1]==nums[2*i-1] || nums[2*i+1]==nums[2*i-2])
                return nums[2*i+1];
            else if(nums[2*i]==nums[2*i+1])
                return nums[2*i];
        }
        return -1;
    }
};
