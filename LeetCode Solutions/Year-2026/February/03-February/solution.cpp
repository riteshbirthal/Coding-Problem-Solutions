class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int count = 0, n = nums.size();
        if(nums[0]>=nums[1])
            return false;
        for(int i = 2; i < n; i++){
            if(nums[i]==nums[i-1])
                return false;
            if((nums[i]-nums[i-1])*(nums[i-1]-nums[i-2])<0)
                count++;
        }
        return count==2;
    }
};
