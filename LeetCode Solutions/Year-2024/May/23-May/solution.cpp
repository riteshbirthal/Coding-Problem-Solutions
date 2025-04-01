class Solution {
public:
    int func(vector<int>& nums, int n, int k, map<int, int>& mp, vector<int>& vec){
        if(n==0){
            for(int i = 0; i < vec.size(); i++) if(vec[i]) return 1;
            return 0;
        }
        int ans1 = 0, ans2 = 0;
        if(!vec[nums[n-1]+k]){
            vec[nums[n-1]]++;
            ans2 = int(pow(2, mp[nums[n-1]]) - 1)*func(nums, n-1, k, mp, vec);
            vec[nums[n-1]]--;
        }
        ans1 = func(nums, n-1, k, mp, vec);
        return ans1 + ans2;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i])==mp.end()) mp[nums[i]] = 1;
            else mp[nums[i]]++;
        }
        vector<int> vec(2001, 0), nums_new;
        for(auto x = mp.begin(); x != mp.end(); x++) nums_new.push_back(x->first);
        return func(nums_new, nums_new.size(), k, mp, vec);
    }
};