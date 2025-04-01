class Solution {
public:
    void func(map<vector<int>, int>& vec, vector<int>& nums, int n,  vector<int>& temp_vec){
        vec[temp_vec]++;
        if(n==nums.size()) return ;
        temp_vec.push_back(nums[n]);
        func(vec, nums, n+1, temp_vec);
        temp_vec.pop_back();
        func(vec, nums, n+1, temp_vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        map<vector<int>, int> mp;
        vector<int> temp_vec;
        func(mp, nums, 0, temp_vec);
        for(auto x = mp.begin(); x != mp.end(); x++) vec.push_back(x->first);
        return vec;
    }
};