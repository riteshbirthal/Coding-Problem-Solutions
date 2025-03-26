class Solution {
    public:
        int longestMonotonicSubarray(vector<int>& nums) {
            int res = 1, n = nums.size(), increasing = 0, len = 1;
            for(int i = 1; i < n; i++){
                if(!increasing){
                    if(nums[i]>nums[i-1]) increasing = 1, len = 2;
                    else if(nums[i]<nums[i-1]) increasing = -1, len = 2;
                    else increasing = 0, len = 1;
                }else if((increasing==1 && nums[i]>nums[i-1]) || (increasing==-1 && nums[i]<nums[i-1])) len++;
                else nums[i]==nums[i-1] ? (len = 1, increasing = 0) : (len = 2, increasing *= -1);
                res = max(res, len);
            }
            return res;
        }
    };