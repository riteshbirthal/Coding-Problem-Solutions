class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        if (n < 2)
            return false;
        unordered_set<int> u_set;
        for (int i = 0; i < n; i++) {
            sum += nums[i], sum %= k;
            if (!sum && i != 0)
                return true;
            if (u_set.find(sum) != u_set.end()) {
                if (nums[i] % k == 0 && nums[i - 1] % k == 0)
                    return true;
                else if (nums[i] % k)
                    return true;
            }
            u_set.insert(sum);
        }
        return false;
    }
};