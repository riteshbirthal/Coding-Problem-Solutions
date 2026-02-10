class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int res = 0, n = nums.size();
        unordered_map<int, int> even, odd;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                nums[j]%2 ? odd[nums[j]]++ : even[nums[j]]++;
                res = odd.size()==even.size() ? max(res, j-i+1) : res;
            }
            odd.clear(); even.clear();
        }
        return res;
    }
};
