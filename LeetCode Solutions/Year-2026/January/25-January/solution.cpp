class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        int res = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(i<k-1)
                continue;
            res = min(res, mp.rbegin()->first - mp.begin()->first);
            mp[nums[i-k+1]]==1 ? mp.erase(nums[i-k+1]) : mp[nums[i-k+1]]--;
        }
        return res;
    }
};
