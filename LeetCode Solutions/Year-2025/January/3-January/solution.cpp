class Solution {
    public:
        int waysToSplitArray(vector<int>& nums) {
            int n = nums.size(), res = 0;
            long long currentSum = 0, total = 0;
            for(int x : nums)
                total += x;
            for(int i = 0; i < n-1; i++){
                currentSum += nums[i];
                if(2*currentSum>=total)
                    res += 1;
            }
            return res;
        }
    };