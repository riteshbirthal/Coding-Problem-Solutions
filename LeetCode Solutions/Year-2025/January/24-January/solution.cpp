class Solution {
    public:
        int checkSafety(vector<vector<int>>& graph, int node, vector<int>& visited, vector<int>& isSafe){
            if(isSafe[node]!=-1) return isSafe[node];
            if(visited[node]) return 0;
            if(graph[node].size()==0) return 1;
            visited[node] = 1;
            int ans = 1;
            for(int child : graph[node]){
                ans = (ans && checkSafety(graph, child, visited, isSafe));
            }
            visited[node] = 0;
            isSafe[node] = ans;
            return ans;
        }
    
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> res, isSafe(n, -1);
            for(int i = 0; i < n; i++){
                if(graph.size()==0) isSafe[i] = 1;
            }
            for(int i = 0; i < n; i++){
                vector<int> visited(n, 0);
                if(isSafe[i]==-1){
                    isSafe[i] = checkSafety(graph, i, visited, isSafe);
                }
                if(isSafe[i])
                    res.push_back(i);
            }
            return res;
        }
    };