class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> vec(100001, 0), ans;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            vec[nums[i]+50000]++;
        for(int i = 0; i < 100001; i++)
            while(vec[i]--)
                ans.push_back(i-50000);
        return ans;
    }
};