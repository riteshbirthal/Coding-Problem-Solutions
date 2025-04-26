class Solution {
public:
    long long countAll(vector<int>& nums, int minK, int maxK){
        if(minK>maxK)
            return 0;
        int left = 0, right = 0, n = nums.size();
        long long res = 0;
        map<int, int> mp;
        while(right<n){
            mp.find(nums[right])==mp.end() ? mp[nums[right]] = 1 : mp[nums[right]]++;
            while(mp.size() && (mp.begin()->first<minK || mp.rbegin()->first>maxK)){
                mp[nums[left]]==1 ? mp.erase(nums[left]) : mp[nums[left]]--;
                left++;
            }
            if(mp.size() && mp.begin()->first>=minK && mp.rbegin()->first<=maxK)
                res += right - left + 1;
            right++;
        }
        while(mp.size() && (mp.begin()->first<minK || mp.rbegin()->first>maxK)){
            mp[nums[left]]==1 ? mp.erase(nums[left]) : mp[nums[left]]--;
            left++;
        }
        return res;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        return countAll(nums, minK, maxK) - countAll(nums, minK+1, maxK) - countAll(nums, minK, maxK-1) + countAll(nums, minK+1, maxK-1);
    }
};