class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long n = nums.size(), sum = 0, count = 0, rem, ans = INT_MAX;
        for(auto x : nums)
            sum += x;
        rem = sum%p;
        if(sum<p) return -1;
        if(sum%p==0) return 0;
        unordered_map<long long, long long> u;
        u[0] = -1, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i]%p;
            if(u.find((sum-rem)%p)!=u.end()){
                ans = min(ans, i-u[(sum-rem)%p]);
            }
            u[sum%p] = i;
        }
        if(ans>=n)
            return -1;
        return ans;
    }
};