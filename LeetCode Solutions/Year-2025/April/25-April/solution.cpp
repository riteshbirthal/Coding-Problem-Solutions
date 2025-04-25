class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long res = 0;
        int n = nums.size();
        unordered_map<int, int> u;
        vector<int> vec(n+1, 0);
        for(int i = 0; i < n; i++){
            vec[i+1] = vec[i];
            if(nums[i]%modulo == k){
                vec[i+1]++;
            }
        }
        for(int x : vec){
            res += u[(x + modulo - k)%modulo];
            u[x%modulo] += 1;
        }
        return res;
    }
};