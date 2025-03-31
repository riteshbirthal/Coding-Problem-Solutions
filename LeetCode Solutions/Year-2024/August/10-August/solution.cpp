class Solution {
    public:
        vector<int> dx, dy;
        void bfs(vector<vector<int>> &vec, int x, int y, int n, int m){
            queue<pair<int, int>> q;
            q.push({x, y});
            vec[x][y] = 1;
            int k;
            while(!q.empty()){
                k = q.size();
                for(int i = 0; i < k; i++){
                    auto [x, y] = q.front();
                    q.pop();
                    for(int j = 0; j < 4; j++){
                        if(x + dx[j] >= 0  &&  x + dx[j] < n  &&  y + dy[j] >= 0  &&  y + dy[j] < m  &&  !vec[x+dx[j]][y+dy[j]])
                            vec[x+dx[j]][y+dy[j]] = 1, q.push({x + dx[j], y + dy[j]});
                    }
                }
            }
        }
        int regionsBySlashes(vector<string>& grid) {
            vector<vector<int>> vec;
            vector<int> r1, r2, r3;
            dx = {0, 0, -1, 1};
            dy = {1, -1, 0, 0};
            int n = grid.size(), m, ans = 0;
            for(int i = 0; i < n; i++){
                m = grid[i].size();
                for(int j = 0; j < m; j++){
                    if(grid[i][j]=='/'){
                        r1.push_back(0);
                        r1.push_back(0);
                        r1.push_back(1);
                        r2.push_back(0);
                        r2.push_back(1);
                        r2.push_back(0);
                        r3.push_back(1);
                        r3.push_back(0);
                        r3.push_back(0);
                    }else if(grid[i][j]==' '){
                        r1.push_back(0);
                        r1.push_back(0);
                        r1.push_back(0);
                        r2.push_back(0);
                        r2.push_back(0);
                        r2.push_back(0);
                        r3.push_back(0);
                        r3.push_back(0);
                        r3.push_back(0);
                    }else{
                        r1.push_back(1);
                        r1.push_back(0);
                        r1.push_back(0);
                        r2.push_back(0);
                        r2.push_back(1);
                        r2.push_back(0);
                        r3.push_back(0);
                        r3.push_back(0);
                        r3.push_back(1);
                    }
                }
                vec.push_back(r1);
                vec.push_back(r2);
                vec.push_back(r3);
                r1.clear();
                r2.clear();
                r3.clear();
            }
            n = vec.size(), m = vec[0].size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(!vec[i][j]){
                        ans++;
                        bfs(vec, i, j, n, m);
                    }
                }
            }
            return ans;
        }
    };