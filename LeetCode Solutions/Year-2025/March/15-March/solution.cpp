class Solution {
    public:
        bool isValid(vector<int>& nums, int n, int k, int maxVal){
            if(k==0)
                return true;
            if(n<0)
                return false;
            bool res = false;
            if(nums[n]<=maxVal){
                res = isValid(nums, n-2, k-1, maxVal);
            }else{
                res = isValid(nums, n-1, k, maxVal);
            }
            return res;
        }
    
        int minCapability(vector<int>& nums, int k) {
            int n = nums.size(), left = 1, right = 1e9, mid, res;
            vector<int> vec(n);
            while(left<=right){
                mid = (left + right) / 2;
                if(isValid(nums, n-1, k, mid)){
                    res = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return res;
        }
    };