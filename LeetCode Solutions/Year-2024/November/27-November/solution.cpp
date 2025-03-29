class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> vec(n);
        int m = queries.size(), q_size, node, dist;
        for(int i = 0; i < n-1; i++)
            vec[i].push_back(i+1);
        queue<int> q;
        for(int i = 0; i < m; i++){
            vec[queries[i][0]].push_back(queries[i][1]);
            vector<int> visited(n, 0);
            q.push(0);
            dist = 0;
            while(!q.empty()){
                q_size = q.size();
                while(q_size--){
                    node = q.front(), q.pop();
                    visited[node] = 1;
                    for(auto x : vec[node]){
                        if(!visited[x] && x==n-1){
                            while(!q.empty()) q.pop();
                            q_size = 0;
                            break;
                        }else if(!visited[x]){
                            q.push(x);
                        }
                    }
                }
                dist++;
            }
            ans.push_back(dist);
        }
        return ans;
    }
};