class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<int> dx, dy;
        dx = {-1, 0, 0, 1};
        dy = {0, -1, 1, 0};
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
        pq.push({{0, 1}, {0, 0}});
        pair<pair<int, int>, pair<int, int>> pr;
        while(!pq.empty()){
            pr = pq.top(), pq.pop();
            int x = pr.second.first, y = pr.second.second, time_step = pr.first.second;
            if(pr.first.first>=dp[x][y])
                continue;
            dp[x][y] = pr.first.first;
            for(int i = 0; i < 4; i++){
                int X = x + dx[i], Y = y + dy[i];
                if(X>=0 && X<n && Y>=0 && Y<m && dp[x][y]+time_step<dp[X][Y]){
                    if(dp[x][y] <= moveTime[X][Y])
                        pq.push({{moveTime[X][Y] + time_step, (time_step==1 ? 2 : 1)}, {X, Y}});
                    else if(dp[x][y] + time_step < dp[X][Y])
                        pq.push({{dp[x][y] + time_step, (time_step==1 ? 2 : 1)}, {X, Y}});
                }
            }
        }           
        return dp[n-1][m-1];
    }
};