class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long long> pq;
        for(auto &n : nums)
            pq.push(n);
        while(k--){
            ans += pq.top();
            pq.push(ceil(((double)pq.top())/3));
            pq.pop();
        }
        return ans;
    }
};