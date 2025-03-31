class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        int ans;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                vec.push_back(sum);
            }
        }
        sort(vec.begin(), vec.end());
        sum = 0;
        for(int i = left - 1; i < right; i++){
            sum += vec[i];
        }
        ans = sum % (long long)(1e9 + 7);
        return ans;
    }
};