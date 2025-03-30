class Solution {
public:
    vector<int> func(vector<int>& nums){
        int n = nums.size();
        vector<int> vec(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[j]>nums[i]){
                    vec[j] = max(vec[j], 1 + vec[i]);
                }
            }
        }
        return vec;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> left(n, 1), right(n, 1);
        left = func(nums);
        reverse(nums.begin(), nums.end());
        right = func(nums);
        reverse(right.begin(), right.end());
        for(int i = 0; i < n; i++){
            if(left[i]>1 && right[i]>1)
                ans = max(ans, left[i] + right[i] - 1);
        }
        return n - max(ans, 3);
    }
};