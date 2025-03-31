class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> mp;
        int n = nums.size(), l = 0, r = 1, ans = 1, mn, mx;
        mp[nums[0]] = 1;
        while(r<n){
            mn = mp.begin()->first, mx = mp.rbegin()->first;
            while((abs(nums[r]-mn)>limit || abs(nums[r]-mx)>limit) && (l<r)){
                if(mp[nums[l]]==1) 
                    mp.erase(nums[l]);
                else 
                    mp[nums[l]]--;
                l++;
                if(!mp.size()) break;
                mn = mp.begin()->first, mx = mp.rbegin()->first;
            }
            if(mp.find(nums[r])==mp.end())
                mp[nums[r]] = 1;
            else
                mp[nums[r]]++;
            ans = max(ans, r-l+1);
            cout << l << " " << r << endl;
            r++;
        }
        return ans;
    }
};