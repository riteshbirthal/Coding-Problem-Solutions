class Solution {
    public:
        long long continuousSubarrays(vector<int>& nums) {
            long long ans = 0;
            int n = nums.size(), left = 0, right = 0;
            map<int, int> mp;
            while(right<n){
                if(mp.size()==0){
                    mp[nums[right]] = 1;
                }else{
                    while(mp.size() && (abs(mp.rbegin()->first - nums[right])>2 || abs(mp.begin()->first - nums[right])>2)){
                        if(mp[nums[left]]==1){
                            mp.erase(nums[left]);
                        }else{
                            mp[nums[left]]--;
                        }
                        left++;
                    }
                    if(mp.find(nums[right])==mp.end()) mp[nums[right]] = 1;
                    else mp[nums[right]]++;
                }
                ans += right - left + 1;
                right++;
            }
            return ans;
        }
    };