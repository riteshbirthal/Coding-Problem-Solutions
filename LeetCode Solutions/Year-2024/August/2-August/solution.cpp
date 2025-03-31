class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), count_ones = 0, count_zeroes = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++)
            count_ones += nums[i];
        for(int i = 0; i < count_ones; i++)
            count_zeroes += nums[i]==0 ? 1 : 0;
        for(int i = 0; i < n; i++){
            count_zeroes += !nums[(i+count_ones)%n];
            count_zeroes -= !nums[i];
            ans = min(ans, count_zeroes); 
        }
        return ans;
    }
};