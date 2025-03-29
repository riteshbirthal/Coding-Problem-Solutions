class Solution {
public:
    int count_set_bits(int n){
        int count = 0;
        while(n){
            count += (n&1);
            n = n >> 1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size(), o_max = INT_MIN, n_min, n_max, set_bits;
        for(int i = 0; i < n; i++){
            set_bits = count_set_bits(nums[i]);
            n_min = INT_MAX, n_max = INT_MIN;
            while(i<n && set_bits==count_set_bits(nums[i])){
                n_min = min(n_min, nums[i]);
                n_max = max(n_max, nums[i]);
                i++;
            }
            i--;
            if(o_max>n_min) return false;
            o_max = n_max;
        }
        return true;
    }
};