//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfsTraverse(vector<vector<int>>& adj, int node, int parent, int &t, vector<bool>& visited, vector<bool>& isAP, vector<int>& discTime, vector<int>& lowestTime){
        int children = 0;
        visited[node] = true;
        discTime[node] = lowestTime[node] = ++t;
        for(int child : adj[node]){
            if(!visited[child]){
                children++;
                dfsTraverse(adj, child, node, t, visited, isAP, discTime, lowestTime);
                
                lowestTime[node] = min(lowestTime[node], lowestTime[child]);
                
                if(parent!=-1 && lowestTime[child]>=discTime[node]){
                    isAP[node] = true;
                }
            }else if(child!=parent){
                lowestTime[node] = min(lowestTime[node], discTime[child]);
            }
        }
        if(parent==-1 && children>1)
            isAP[node] = true;
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> res, discTime(V, 0), lowestTime(V, 0);
        vector<bool> visited(V, false), isAP(V, false);
        int t = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfsTraverse(adj, i, -1, t, visited, isAP, discTime, lowestTime);
            }
        }
        for(int i = 0; i < V; i++){
            if(isAP[i])
                res.push_back(i);
        }
        return res.size() ? res : vector<int>{-1};
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
