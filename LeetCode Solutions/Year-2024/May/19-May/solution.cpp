class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0, min_big = LONG_MAX, max_small = LONG_MIN, temp;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) ans += nums[i];
        vector<long long> big, small;
        for(int i = 0; i < nums.size(); i++){
            temp = (nums[i]^k) - nums[i];
            if(temp > 0) ans += temp, min_big = min(min_big, temp), count++;
            else max_small = max(max_small, temp);
        }
        if(count%2){
            if(max_small + min_big > 0) ans += max_small;
            else ans -= min_big;
        }
        return ans;
    }
};