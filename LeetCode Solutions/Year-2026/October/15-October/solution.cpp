class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> dist;
            for(int j = i; j < n; j++){
                dist.insert(nums[j]);
                res += dist.size()*dist.size();
            }
        }
        return res;
    }
};
