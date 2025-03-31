class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, sum = 0;
        unordered_map<int, int> u_set;
        u_set[0] = 1;
        for(int i = 0; i < n; i++){
            sum += (nums[i])%k;
            sum = (sum+k)%k;
            if(u_set.find(sum)!=u_set.end()) ans += u_set[sum];
            if(u_set.find(sum)!=u_set.end()) u_set[sum]++;
            else u_set[sum] = 1;
        }
        return ans;
    }
};