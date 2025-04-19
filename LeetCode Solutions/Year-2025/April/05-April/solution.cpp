class Solution {
public:
    int func(vector<int>& nums, int n, int k){
        if(n==0) return k;
        return func(nums, n-1, k) + func(nums, n-1, k^nums[n-1]);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return func(nums, n, 0);
    }
};
