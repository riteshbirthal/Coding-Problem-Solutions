class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long res = 0;
            vector<int> left(n, nums[0]), right(n, nums[n-1]);
            for(int i = 1; i < n; i++){
                left[i] = max(left[i-1], nums[i-1]);
                right[n-1-i] = max(right[n-i], nums[n-i]);
            }
            for(int i = 1; i < n-1; i++){
                res = max(res, (long long)(left[i]-nums[i])*right[i]);
            }
            return res;
        }
    };