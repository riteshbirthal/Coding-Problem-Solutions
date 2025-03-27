class Solution {
    public:
        vector<int> dfs(int node, int parent, vector<int>& visited, unordered_set<int>& u, vector<vector<int>>& vec){
            if(u.find(node)!=u.end()){
                vector<int> res;
                int n = visited.size(), found = 0;
                for(int i = 0; i < n; i++){
                    if(visited[i]==node) found = 1;
                    if(found){
                        res.push_back(visited[i]);
                    }
                }
                return res;
            }
            u.insert(node);
            visited.push_back(node);
            vector<int> res;
            for(auto child : vec[node]){
                if(child != parent){
                    res = dfs(child, node, visited, u, vec);
                    if(res.size()){
                        visited.pop_back();
                        u.erase(node);
                        return res;
                    }
                }
            }
            visited.pop_back();
            u.erase(node);
            return res;
        }
    
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            vector<int> res, visited, cycle;
            vector<vector<int>> vec(n+1);
            for(auto edge : edges){
                vec[edge[0]].push_back(edge[1]);
                vec[edge[1]].push_back(edge[0]);
            }
            unordered_set<int> u;
            set<vector<int>> cycleEdges;
            cycle = dfs(1, -1, visited, u, vec);
            n = cycle.size();
            for(int i = 0; i <= n; i++){
                cycleEdges.insert({cycle[i%n], cycle[(i+1)%n]});
                cycleEdges.insert({cycle[(i+1)%n], cycle[i%n]});
            }
            n = edges.size();
            for(int i = n-1; i >= 0; i--){
                if(cycleEdges.find(edges[i])!=cycleEdges.end()){
                    res = edges[i];
                    break;
                }
            }
            return res;
        }
    };