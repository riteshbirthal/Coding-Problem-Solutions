class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0, sum = 0, n = nums.size(), left = nums[0];
        for(int x : nums)
            sum += x;
        for(int i = 1; i < n; i++){
            res += abs(sum-2*left)%2==0;
            left += nums[i];
        }
        return res;
    }
};
