class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int res = 0;
            long long first, second;
            priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
            while(pq.top()<k){
                first = pq.top(), pq.pop();
                second = pq.top(), pq.pop();
                pq.push(2*first + second);
                res += 1;
            }
            return res;
        }
    };