class Solution {
public:
    int func(vector<int>& nums, int n, int curr, int mxOr, map<vector<int>, int>& mp){
        if(n==0)
            return curr==mxOr;
        if(mp.find({n, curr})!=mp.end())
            return mp[{n, curr}];
        return mp[{n, curr}] = func(nums, n-1, curr | nums[n-1], mxOr, mp) + func(nums, n-1, curr, mxOr, mp);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int mxOr = 0, ans = 0;
        for(auto n : nums)
            mxOr |= n;
        map<vector<int>, int> mp;
        ans = func(nums, nums.size(), 0, mxOr, mp);
        return ans;
    }
};