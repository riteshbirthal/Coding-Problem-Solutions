class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<int> dx, dy;
        dx = {-1, 0, 0, 1};
        dy = {0, -1, 1, 0};
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        pair<int, pair<int, int>> pr;
        while(!pq.empty()){
            pr = pq.top(), pq.pop();
            int x = pr.second.first, y = pr.second.second;
            if(pr.first>=dp[x][y])
                continue;
            dp[x][y] = pr.first;
            for(int i = 0; i < 4; i++){
                int X = x + dx[i], Y = y + dy[i];
                if(X>=0 && X<n && Y>=0 && Y<m && dp[x][y]+1<dp[X][Y]){
                    if(dp[x][y]+1<=moveTime[X][Y])
                        pq.push({moveTime[X][Y]+1, {X, Y}});
                    else if(dp[x][y]<dp[X][Y])
                        pq.push({dp[x][y]+1, {X, Y}});
                }
            }
        }           
        return dp[n-1][m-1];
    }
};