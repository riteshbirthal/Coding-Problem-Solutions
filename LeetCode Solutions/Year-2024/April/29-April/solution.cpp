class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++) k ^= nums[i];
        int ans = 0;
        while(k){
            if(k%2) ans++;
            k = k/2;
        }
        return ans;
    }
};