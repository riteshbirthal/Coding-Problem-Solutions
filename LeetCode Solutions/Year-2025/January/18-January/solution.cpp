class Solution {
    public:
        int minCost(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size(), res = INT_MAX, X, Y;
            vector<vector<vector<int>>> vec(n, vector<vector<int>>(m, {INT_MAX, INT_MAX, INT_MAX, INT_MAX}));
            queue<vector<int>> q;
            vector<int> v;
            q.push({0, 0, grid[0][0], 0});
            vec[0][0][grid[0][0]-1] = 0;
            vector<vector<int>> direction{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            while(q.size()){
                v = q.front(), q.pop();
                int x = v[0], y = v[1], dir = v[2], cost = v[3]; 
                if(x==n-1 && y==m-1)
                    continue;
                for(int i = 0; i < 4; i++){
                    X = x + direction[i][0], Y = y + direction[i][1];
                    if(dir==i+1){
                        if(X>=0 && X<n && Y>=0 && Y<m && vec[X][Y][grid[X][Y]-1]>cost){
                            vec[X][Y][grid[X][Y]-1] = cost;
                            q.push({X, Y, grid[X][Y], cost});
                        }
                    }else{
                        if(X>=0 && X<n && Y>=0 && Y<m && vec[X][Y][grid[X][Y]-1]>cost+1){
                            vec[X][Y][grid[X][Y]-1] = cost+1;
                            q.push({X, Y, grid[X][Y], cost+1});
                        }
                    }
                }
            }
            res = *min_element(vec[n-1][m-1].begin(), vec[n-1][m-1].end());
            return res;
        }
    };