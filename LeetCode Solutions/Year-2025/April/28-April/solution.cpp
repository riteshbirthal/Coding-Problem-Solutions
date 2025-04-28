class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res = 0;
        int n = nums.size(), left, right, mid, idx;
        vector<long long> pre_sum(n+1, 0);
        for(int i = 0; i < n; i++)
            pre_sum[i+1] = nums[i] + pre_sum[i];
        for(int i = 0; i < n; i++){
            left = 0, right = i+1, idx = i+1;
            while(left<=right){
                mid = (left + right) / 2;
                if((pre_sum[i+1]-pre_sum[mid])*(i+1-mid) < k){
                    idx = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            res += (i+1-idx);
        }
        return res;
    }
};
