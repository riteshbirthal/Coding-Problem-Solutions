class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pre = 0, ans = 1;
        for(int i = 0; i < nums.size(); i++){
            ans = nums.size()-i;
            if(i==0 && ans<=nums[i]) return ans;
            else if(i && ans>nums[i-1] && ans<=nums[i]) return ans;
        }
        return -1;
    }
};