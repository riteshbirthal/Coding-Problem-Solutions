class Solution {
public:
    static bool sort_func(vector<int>& a, vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1] > b[1];
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        vector<vector<int>> vec;
        for(auto x = mp.begin(); x != mp.end(); x++)
            vec.push_back({x->second, x->first});
        sort(vec.begin(), vec.end(), sort_func);
        vector<int> ans;
        for(int i = 0; i < vec.size(); i++)
            while(vec[i][0])
                ans.push_back(vec[i][1]), vec[i][0]--;
        return ans;
    }
};