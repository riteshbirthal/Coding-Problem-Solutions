class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        map<int, vector<int>> x, y;
        int ans = 0, n = stones.size(), k;
        for(int i = 0; i < n; i++){
            x[stones[i][0]].push_back(stones[i][1]);
            y[stones[i][1]].push_back(stones[i][0]);
        }
        queue<vector<int>> q;
        map<vector<int>, int> visited;
        vector<int> vec;
        for(int i = 0; i < n; i++){
            if(visited.find(stones[i])==visited.end()){
                ans++;
                visited[stones[i]]++;
                q.push(stones[i]);
                while(!q.empty()){
                    k = q.size();
                    for(int j = 0; j < k; j++){
                        vec = q.front(), q.pop();
                        for(auto new_y : x[vec[0]]){
                            if(visited.find({vec[0], new_y})==visited.end()){
                                q.push({vec[0], new_y});
                                visited[{vec[0], new_y}]++;
                            }
                        }
                        for(auto new_x : y[vec[1]]){
                            if(visited.find({new_x, vec[1]})==visited.end()){
                                q.push({new_x, vec[1]});
                                visited[{new_x, vec[1]}]++;
                            }
                        }
                    }
                }
            }
        }
        ans = n - ans;
        return ans;
    }
};