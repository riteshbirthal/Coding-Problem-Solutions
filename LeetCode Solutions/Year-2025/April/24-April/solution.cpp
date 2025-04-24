class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, disCount = set<int>(nums.begin(), nums.end()).size(), rCount, lCount, res = 0;
        unordered_map<int, int> u;
        while(right<n){
            u.find(nums[right])==u.end() ? u[nums[right]] = 1 : u[nums[right]]++;
            rCount = n-right;
            lCount = 0;
            while(left<=right && u.size()==disCount){
                lCount++;
                u[nums[left]]==1 ? u.erase(nums[left]) : u[nums[left]]--;
                left++;
            }
            res += lCount * rCount;
            right++;
        }
        return res;
    }
};