//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int res = 0, n = mat.size(), m = mat[0].size();
        vector<int> dx, dy;
        dx = {-1, 0, 0, 1};
        dy = {0, -1, 1, 0};
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]==2)
                    q.push({i, j});
            }
        }
        while(!q.empty()){
            int k = q.size(), isRotted = 0;
            while(k--){
                pair<int, int> pr = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int x = pr.first + dx[i], y = pr.second + dy[i];
                    if(x>=0 && y>=0 && x<n && y<m && mat[x][y]==1){
                        mat[x][y] = 2;
                        q.push({x, y});
                        isRotted = 1;
                    }
                }
            }
            if(isRotted)
                res++;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]==1)
                    return -1;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends