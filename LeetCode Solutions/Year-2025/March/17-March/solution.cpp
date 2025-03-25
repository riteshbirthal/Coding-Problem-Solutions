class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size()/2;
            bool res = true;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < n; i++){
                res = res && nums[2*i]==nums[2*i+1];
            }
            return res;
        }
    };