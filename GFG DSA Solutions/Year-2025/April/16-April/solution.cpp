//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for(int i = 0; i < n; i++){
            vector<int> dis(n, 1e8);
            dis[i] = 0;
            vector<vector<int>> vec(n);
            map<pair<int, int>, int> wt;
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(j==k || dist[j][k]==1e8)
                        continue;
                    vec[j].push_back(k);
                    wt[{j, k}] = dist[j][k];
                }
            }
            queue<pair<int, int>> q;
            q.push({i, 0});
            pair<int, int> pr;
            while(!q.empty()){
                pr = q.front(), q.pop();
                for(int v : vec[pr.first]){
                    if(dis[v] > pr.second + wt[{pr.first, v}]){
                        dis[v] = pr.second + wt[{pr.first, v}];
                        q.push({v, dis[v]});
                    }
                }
            }
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dis[j]);
            }
        }
        return ;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends