//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited){
        visited[node] = 1;
        for(int child : adj[node])
            if(!visited[child])
                dfs(adj, child, visited);
        return ;
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);
        for(auto e : edges){
            if((e[0]==c && e[1]==d) || (e[0]==d && e[1]==c)){
                continue;
            }
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int preComp = 0, actComp = 0;
        for(int i = 0; i < V; i++)
            if(!visited[i])
                dfs(adj, i, visited), preComp++;
        visited = vector<bool>(V, false);
        adj[c].push_back(d);
        adj[d].push_back(c);
        for(int i = 0; i < V; i++)
            if(!visited[i])
                dfs(adj, i, visited), actComp++;
        return actComp!=preComp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
