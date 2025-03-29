class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int xor_ = 0, k, n = nums.size();
        for(auto x : nums)
            xor_ ^= x;
        for(int i = 0; i < n; i++){
            k = 0;
            for(int j = 0; j < maximumBit; j++){
                if((xor_ & (1<<j)) == 0)
                    k += (1<<j);
            }
            ans.push_back(k);
            xor_ ^= nums[n-1-i];
        }
        return ans;
    }
};