class Solution {
    public:
        vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            int n = nums.size();
            for(int i = 0; i < n; i++){
                pq.push({nums[i], i});
            }
            pair<int, int> pr;
            for(int i = 0; i < k; i++){
                pr = pq.top();
                pq.pop();
                pq.push({multiplier * pr.first, pr.second});
            }
            while(!pq.empty()){
                pr = pq.top();
                pq.pop();
                nums[pr.second] = pr.first;
            }
            return nums;
        }
    };