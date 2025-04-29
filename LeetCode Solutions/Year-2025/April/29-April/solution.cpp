class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele = 0;
        for(int i = 0; i < nums.size(); i++) max_ele = max(max_ele, nums[i]);
        vector<int> idx;
        for(int i = 0; i < nums.size(); i++) if(nums[i]==max_ele) idx.push_back(i);
        if(idx.size()<k) return 0;
        long long ans = 1;
        for(int i = 0; i < idx.size()-k+1; i++){
            if(i+k==idx.size()){
                ans += (long long)(idx[i]+1)*(long long)(nums.size()-idx[i+k-1]) - 1;
            }else{
                ans += (long long)(idx[i]+1)*(long long)(idx[i+k]-idx[i+k-1]) - 1;
            }
        }
        return ans+(long long)idx.size()-k;
    }
};
