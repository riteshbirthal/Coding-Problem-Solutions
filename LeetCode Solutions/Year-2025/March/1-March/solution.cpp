class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size(), idx = 0;
            for(int i = 0; i < n-1; i++){
                nums[i]==nums[i+1] ? (nums[i] *= 2, nums[i+1] = 0) : idx = 0;
            }
            vector<int> res(n, 0);
            for(int i = 0; i < n; i++){
                nums[i] ? (res[idx] = nums[i], idx++) : idx = idx;
            }
            return res;
        }
    };