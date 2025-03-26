class Solution {
    public:
        int maxAscendingSum(vector<int>& nums) {
            int n = nums.size(), res = nums[0], sum = nums[0];
            for(int i = 1; i < n; i++){
                nums[i]>nums[i-1] ? sum += nums[i] : sum = nums[i];
                res = max(res, sum);
            }
            return res;
        }
    };