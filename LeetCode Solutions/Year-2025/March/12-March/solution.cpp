class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n = nums.size(), left = 0, right = n-1, mid, l_idx = -1, h_idx = n, res;
            while(left<=right){
                mid = (left + right) / 2;
                if(nums[mid]<0){
                    l_idx = mid;
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            left = 0, right = n-1;
            while(left<=right){
                mid = (left + right) / 2;
                if(nums[mid]>0){
                    h_idx = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            res = max(n - h_idx, l_idx + 1);
            return res;
        }
    };