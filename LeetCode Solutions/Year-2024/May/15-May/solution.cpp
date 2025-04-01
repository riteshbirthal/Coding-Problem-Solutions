class Solution {
public:
    bool check(int x, int y, int n){
        return x>=0 && y>=0 && x<n && y<n;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), level = 0, x, y, t;
        vector<vector<int>> vec(n, vector<int>(n, INT_MAX)), visited(n, vector<int>(n, 0));
        queue<vector<int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j]) 
                    q.push({i,j}), visited[i][j] = 1;
        while(!q.empty()){
            t = q.size();
            for(int i = 0; i < t; i++){
                x = q.front()[0], y = q.front()[1];
                q.pop();
                vec[x][y] = level;
                // cout << x << " " << y << " " << level << endl;
                if(check(x+1, y, n) && !visited[x+1][y]) q.push({x+1, y}), visited[x+1][y] = 1;
                if(check(x, y+1, n) && !visited[x][y+1]) q.push({x, y+1}), visited[x][y+1] = 1;
                if(check(x-1, y, n) && !visited[x-1][y]) q.push({x-1, y}), visited[x-1][y] = 1;
                if(check(x, y-1, n) && !visited[x][y-1]) q.push({x, y-1}), visited[x][y-1] = 1;
            }
            level++;
        }
        visited.clear();
        visited.resize(n, vector<int>(n, 0));
        priority_queue<vector<int>> pq;
        pq.push({vec[0][0], 0, 0});
        visited[0][0] = 1;
        int ans = vec[0][0];
        vector<int> temp;
        while(!pq.empty()){
            temp = pq.top();
            // cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
            pq.pop();
            x = temp[1], y = temp[2];
            if(check(x+1, y, n) && !visited[x+1][y]) pq.push({vec[x+1][y], x+1, y}), visited[x+1][y] = 1;
            if(check(x, y+1, n) && !visited[x][y+1]) pq.push({vec[x][y+1], x, y+1}), visited[x][y+1] = 1;
            if(check(x-1, y, n) && !visited[x-1][y]) pq.push({vec[x-1][y], x-1, y}), visited[x-1][y] = 1;
            if(check(x, y-1, n) && !visited[x][y-1]) pq.push({vec[x][y-1], x, y-1}), visited[x][y-1] = 1;
            ans = min(ans, temp[0]);
            if(x==n-1 && y==n-1) break;
        }
        return ans;
    }
};