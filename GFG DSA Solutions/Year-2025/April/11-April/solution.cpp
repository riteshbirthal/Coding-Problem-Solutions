//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> res(V, INT_MAX);
        res[src] = 0;
        vector<vector<int>> adj(V);
        map<pair<int, int>, int> wt;
        for(auto e : edges){
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
            wt[{e[0], e[1]}] = wt[{e[1], e[0]}] = e[2];
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        pair<int, int> pr;
        while(!q.empty()){
            pr = q.front(), q.pop();
            for(int child : adj[pr.first]){
                if(res[child] > pr.second + wt[{pr.first, child}]){
                    res[child] = pr.second + wt[{pr.first, child}];
                    q.push({child, res[child]});
                }
            }
        }
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
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
