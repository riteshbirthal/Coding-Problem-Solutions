//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclePresent(vector<vector<int>>& adj, int node, int parent, vector<int>& visited){
        bool res = false;
        visited[node] = 1;
        for(int child : adj[node]){
            if(child!=parent && !visited[child]){
                res = res || isCyclePresent(adj, child, node, visited);
            }else if(child!=parent){
                return true;
            }
        }
        return res;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> visited(V, 0);
        int res = false;
        for(int i = 0; i < V; i++)
            if(!visited[i])
                res = res || isCyclePresent(adj, i, -1, visited);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
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