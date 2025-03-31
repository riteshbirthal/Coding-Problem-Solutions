class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sz = nums.size(), mn = 0, mx = 0, ans = 0;
        for(int i = 0; i < sz; i++){
            if(mx==nums[i]-1){
                mx += nums[i];
            }else if(mx<nums[i]-1){
                ans++;
                mx += mx + 1;
                i--;
            }else{
                mx += nums[i];
            }
            if(mx>=n) break;
        }
        while(mx<n){
            mx += (mx+1);
            ans++;
        }
        return ans;
    }
};