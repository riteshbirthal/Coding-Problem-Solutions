class Solution {
public:
    map<int, int> mp;
    int get_new_num(int n){
        if(n==0) return mp[n];
        int new_num = 0, idx = 0;
        while(n){
            new_num = mp[(n % 10)] * pow(10, idx) + new_num;
            n /= 10, idx++;
        }
        return new_num;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = mapping.size();
        for(int i = 0; i < n; i++)
            mp[mapping[i]] = mapping[mapping[i]];
        vector<vector<int>> vec;
        n = nums.size();
        for(int i = 0; i < n; i++)
            vec.push_back({get_new_num(nums[i]), i, nums[i]});
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n; i++)
            nums[i] = vec[i][2];
        return nums;
    }
};