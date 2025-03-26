class Solution {
    public:
        int tupleSameProduct(vector<int>& nums) {
            int n = nums.size(), res = 0;
            unordered_map<int, int> mp;
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    mp.find(nums[i]*nums[j])==mp.end() ? mp[nums[i]*nums[j]] = 1 : mp[nums[i]*nums[j]]++;
                }
            }
            for(auto x = mp.begin(); x != mp.end(); x++)
                res += x->second * (x->second - 1);
            return 4*res;
        }
    };