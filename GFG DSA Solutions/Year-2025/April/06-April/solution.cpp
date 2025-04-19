//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dfs(vector<vector<int>>& vec, int node, vector<int>& visited){
        int res = 1;
        for(int child : vec[node]){
            if(!visited[child]){
                res = max(res, dfs(vec, child, visited));
            }else{
                res = max(res, visited[child]);
            }
        }
        return visited[node] = res + 1;
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> vec(V);
        for(auto e : edges)
            vec[e[0]].push_back(e[1]);
        vector<int> visited(V, 0), res;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                visited[i] = dfs(vec, i, visited) + 1;
            }
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < V; i++)
            pq.push({visited[i], i});
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
