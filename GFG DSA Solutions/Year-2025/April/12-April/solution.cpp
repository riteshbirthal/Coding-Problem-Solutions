//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int color = image[sr][sc], n = image.size(), m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> dx, dy;
        dx = {-1, 0, 0, 1};
        dy = {0, -1, 1, 0};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        pair<int, int> pr;
        while(!q.empty()){
            pr = q.front(), q.pop();
            for(int i = 0; i < 4; i++){
                int X = pr.first + dx[i], Y = pr.second + dy[i];
                if(X>=0 && X<n && Y>=0 && Y<m && image[X][Y]==color && !visited[X][Y]){
                    image[X][Y] = newColor;
                    visited[X][Y] = true;
                    q.push({X, Y});
                }
            }
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
