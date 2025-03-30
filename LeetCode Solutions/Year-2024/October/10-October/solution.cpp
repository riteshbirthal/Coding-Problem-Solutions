class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), n = nums.size(), ans = 0;
        vector<int> v(mx+1, INT_MAX);
        unordered_map<int, int> ul, ur;
        for(int i = 0; i < n; i++){
            if(ul.find(nums[i])==ul.end())
                ul[nums[i]] = i;
            ur[nums[i]] = i;
        }
        int mn = INT_MAX;
        for(int i = 0; i < mx+1; i++){
            if(ul.find(i)!=ul.end())
                v[i] = min(mn, ul[i]), mn = min(mn, v[i]), ans = max(ans, ur[i]-mn);
            else
                v[i] = mn, mn = min(mn, v[i]);
        }
        return ans;
    }
};