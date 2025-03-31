class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0, ans = 0, mx = *max_element(nums.begin(), nums.end());
        for(auto x : nums){
            if(x==mx){
                count++;
                ans = max(ans, count);
            }else{
                count = 0;
            }
        }
        return ans;
    }
};