class Solution {
    public:
        int bfs(vector<vector<int>>& vec, int node, vector<int>& visited){
            int nodes = 1;
            queue<int> q;
            q.push(node);
            visited[node] = 1;
            while(!q.empty()){
                node = q.front(), q.pop();
                for(int n : vec[node]){
                    if(!visited[n]){
                        nodes++;
                        q.push(n);
                        visited[n] = 1;
                    }
                }
            }
            return nodes;
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            int res = 0, nodes;
            vector<vector<int>> vec(n);
            for(vector<int> e : edges){
                vec[e[0]].push_back(e[1]);
                vec[e[1]].push_back(e[0]);
            }
            vector<int> visited(n, 0), pre_vis(n, 0);
            for(int i = 0; i < n; i++){
                if(!visited[i]){
                    nodes = bfs(vec, i, visited);
                    int isComplete = 1;
                    for(int j = 0; j < n; j++){
                        if(visited[j]!=pre_vis[j]){
                            isComplete = isComplete && (vec[j].size()==nodes-1);
                        }
                    }
                    res += isComplete;
                    pre_vis = visited;
                }
            }
            return res;
        }
    };