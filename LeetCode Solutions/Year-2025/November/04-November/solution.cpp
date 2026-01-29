class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(), total;
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(i<k-1)
                continue;
            vector<int> vec(51, 0);
            for(int j = i-k+1; j <= i; j++)
                vec[nums[j]]++;
            priority_queue<pair<int, int>> pq;
            for(int j = 0; j < 51; j++)
                pq.push({vec[j], j});
            total = 0;
            for(int j = 0; j < x; j++)
                total += pq.top().first * pq.top().second, pq.pop();
            res.push_back(total);
        }
        return res;
    }
};
