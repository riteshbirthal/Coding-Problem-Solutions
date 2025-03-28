class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            vector<int> qrs = queries, dx, dy, res;
            dx = {-1, 0, 0, 1};
            dy = {0, -1, 1, 0};
            sort(qrs.begin(), qrs.end());
            int n = grid.size(), m = grid[0].size(), count = 0, X, Y, idx = 0, k = qrs.size();
            vector<vector<int>> visited(n, vector<int>(m, 0));
            map<int, int> mp;
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            pair<int, pair<int, int>> pr;
            pq.push({grid[0][0], {0, 0}});
            visited[0][0] = 1;
            while(!pq.empty() && idx<k){
                if(idx<k && pq.top().first>=qrs[idx]){
                    mp[qrs[idx]] = count, idx++;
                    continue;
                }
                pr = pq.top(), pq.pop();
                count++;
                for(int i = 0; i < 4; i++){
                    X = pr.second.first + dx[i], Y = pr.second.second  + dy[i];
                    if(X>=0 && X<n && Y>=0 && Y<m && !visited[X][Y]){
                        pq.push({grid[X][Y], {X, Y}});
                        visited[X][Y] = 1;
                    }
                }
            }
            while(idx<k)
                mp[qrs[idx++]] = m*n;
            for(int i = 0; i < k; i++)
                res.push_back(mp[queries[i]]);
            return res;
        }
    };