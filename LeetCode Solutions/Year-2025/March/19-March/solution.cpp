class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int res = 0, n = nums.size();
            for(int i = 0; i < n-2; i++){
                if(!nums[i]){
                    nums[i] = !nums[i], nums[i+1] = !nums[i+1], nums[i+2] = !nums[i+2];
                    res += 1;
                }
            }
            return (nums[n-2]==0 || nums[n-1]==0) ? -1 : res;
        }
    };