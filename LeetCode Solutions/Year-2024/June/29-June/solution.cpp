class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vec(n), parent(n);
        vector<int> visited(n, 0), result;
        for(int i = 0; i < edges.size(); i++){
            parent[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        int k, node;
        for(int i = 0; i < n; i++){
            q.push(i);
            while(!q.empty()){
                k = q.size();
                for(int j = 0; j < k; j++){
                    node = q.front(), q.pop();
                    for(int l = 0; l < parent[node].size(); l++){
                        if(!visited[parent[node][l]])
                            q.push(parent[node][l]), visited[parent[node][l]] = 1, result.push_back(parent[node][l]);
                    }
                }
            }
            sort(result.begin(), result.end());
            vec[i] = result;
            visited = vector<int>(n, 0);
            result.clear();
        }
        return vec;
    }
};