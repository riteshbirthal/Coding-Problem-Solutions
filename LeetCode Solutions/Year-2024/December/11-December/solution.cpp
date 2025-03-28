class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int n = nums.size(), left = 1, right = n, mid, ans = 1;
            bool flag;
            while(left<=right){
                mid = (left + right) / 2;
                flag = false;
                for(int i = 0; i < n-mid+1 && !flag; i++){
                    if(nums[i+mid-1]-nums[i]<=2*k)
                        flag = true;
                }
                if(flag){
                    ans = max(ans, mid);
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            return ans;
        }
    };