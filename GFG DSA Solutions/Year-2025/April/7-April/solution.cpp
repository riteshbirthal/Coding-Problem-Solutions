//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclePresent(vector<vector<int>>& adj, int node, vector<bool>& visited, vector<int>& dp){
        bool res = false;
        if(dp[node]!=-1)
            return (bool)dp[node];
        for(int child : adj[node]){
            if(!visited[child]){
                visited[child] = true;
                res = res || isCyclePresent(adj, child, visited, dp);
                visited[child] = false;
            }else{
                return dp[node] = true;
            }
        }
        return dp[node] = res;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> vec(V);
        for(auto e : edges)
            vec[e[0]].push_back(e[1]);
        vector<bool> visited(V, false);
        vector<int> dp(V, -1);
        bool res = false;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                visited[i] = true;
                res = res || (bool)isCyclePresent(vec, i, visited, dp);
                visited[i] = false;
            }
        }
        return (bool)res;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
