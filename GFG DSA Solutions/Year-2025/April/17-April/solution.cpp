//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMin(vector<vector<int>>& adj, int node, int parent, int currDis, vector<int>& visited, map<pair<int, int>, int>& wt, vector<int>& dist, vector<vector<int>>& dp){
        if(dp[node][currDis]!=-1)
            return dp[node][currDis];
        int res = INT_MAX;
        visited[node] = 1;
        dist[node] = currDis;
        for(int child : adj[node]){
            if(child==parent)
                continue;
            if(!visited[child]){
                res = min(res, getMin(adj, child, node, currDis + wt[{node, child}], visited, wt, dist, dp));
            }else{
                res = min(res, currDis + wt[{node, child}] - dist[child]);
            }
        }
        visited[node] = 0;
        dist[node] = 0;
        return dp[node][currDis] = res;
    }
     
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        map<pair<int, int>, int> wt;
        vector<vector<int>> dp(V, vector<int>(1e4+1, -1));
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
            wt[{e[0], e[1]}] = wt[{e[1], e[0]}] = e[2];
        }
        vector<int> visited(V, 0), dist(V, 0);
        int res = getMin(adj, 0, -1, 0, visited, wt, dist, dp);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends