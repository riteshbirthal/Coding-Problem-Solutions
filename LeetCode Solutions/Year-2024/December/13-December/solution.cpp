class Solution {
    public:
        long long findScore(vector<int>& nums) {
            long long score = 0;
            int n = nums.size();
            vector<int> visited(n, 0), v;
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            for(int i = 0; i < n; i++)
                pq.push({nums[i], i});
            while(pq.size()){
                if(!visited[pq.top()[1]]){
                    v = pq.top();
                    visited[v[1]] = 1;
                    score += v[0];
                    if(v[1]-1>=0)
                        visited[v[1]-1] = 1;
                    if(v[1]+1<n)
                        visited[v[1]+1] = 1;
                    visited[v[1]] = 1;
                }
                pq.pop();
            }
            return score;
        }
    };