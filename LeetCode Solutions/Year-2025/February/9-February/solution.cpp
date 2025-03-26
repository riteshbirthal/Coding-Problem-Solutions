class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int, int> u;
            int n = nums.size();
            long long res = 0;
            for(int i = 0; i < n; i++)
                u.find(nums[i]-i)==u.end() ? u[nums[i]-i] = 1 : u[nums[i]-i]++;
            for(auto x = u.begin(); x != u.end(); x++){
                n -= x->second;
                res += (long long)(x->second)*(long long)(n);
            }
            return res;
        }
    };