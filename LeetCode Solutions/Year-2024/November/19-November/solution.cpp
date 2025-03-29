class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < k-1; i++){
            if(mp.find(nums[i])==mp.end()) mp[nums[i]] = 1;
            else mp[nums[i]]++;
            sum += nums[i];
        }
        for(int i = k-1; i < n; i++){
            if(mp.find(nums[i])==mp.end()) mp[nums[i]] = 1;
            else mp[nums[i]]++;
            sum += nums[i];
            if(mp.size()==k) ans = max(ans, sum);
            if(mp[nums[i-k+1]]==1) mp.erase(nums[i-k+1]);
            else mp[nums[i-k+1]]--;
            sum -= nums[i-k+1];
        }
        return ans;
    }
};