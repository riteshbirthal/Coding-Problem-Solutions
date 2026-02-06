class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = n, left, right, mid;
        long long val;
        for(int i = 0; i < n; i++){
            left = i, right = n-1;
            val = (long long)nums[i] * (long long)k;
            while(left<=right){
                mid = (left + right) / 2;
                if(nums[mid]<=val){
                    res = min(res, n - (mid-i+1));
                    left = mid + 1;
                }else
                    right = mid - 1;
            }
        }
        return res;
    }
};
