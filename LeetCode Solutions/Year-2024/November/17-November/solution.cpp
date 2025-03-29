class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        vector<long long> prefix = {0};
        for(int i = 0; i < n; i++){
            prefix.push_back(prefix[prefix.size()-1] + nums[i]);
        }
        deque<int> dq;
        for(int i = 0; i <= n; i++){
            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[i]<=prefix[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans<=n ? ans : -1;
    }
};