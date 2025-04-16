class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size(), left = 0, right = 0, pairs = 0;
        unordered_map<int, int> count;
        while(right<n){
            count.find(nums[right])==count.end() ? count[nums[right]] = 1 : count[nums[right]]++;
            pairs += count[nums[right]] - 1;
            if(pairs>=k){
                long long r = n - right, l = 1;
                while(true){
                    pairs -= count[nums[left]] - 1;
                    count[nums[left]]==1 ? count.erase(nums[left]) : count[nums[left]]--;
                    left++;
                    if(pairs<k)
                        break;
                    else
                        l += 1;
                }
                res += l*r;
            }
            right++;
        }
        return res;
    }
};