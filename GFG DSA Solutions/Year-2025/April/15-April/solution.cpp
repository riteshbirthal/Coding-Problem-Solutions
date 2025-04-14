//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool negativeCycle;
    void dfs(vector<vector<int>>& adj, int node, int currDis, map<pair<int, int>, int>& wt, vector<int>& isAnc, vector<int>& res){
        isAnc[node] = 1;
        res[node] = currDis;
        for(int child : adj[node]){
            if(!isAnc[child] && res[child] > wt[{node, child}] + currDis){
                dfs(adj, child, currDis + wt[{node, child}], wt, isAnc, res);
            }else if(isAnc[child] && res[child] > wt[{node, child}] + currDis){
                negativeCycle = true;
                return ;
            }
        }
        isAnc[node] = 0;
        return ;
    }
    
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        map<pair<int, int>, int> wt;
        vector<vector<int>> adj(V);
        vector<int> res(V, 1e8);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            wt[{e[0], e[1]}] = e[2];
        }
        negativeCycle = false;
        vector<int> isAnc(V, 0);
        dfs(adj, src, 0, wt, isAnc, res);
        if(negativeCycle)
            return vector<int>{-1};
        return res;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends