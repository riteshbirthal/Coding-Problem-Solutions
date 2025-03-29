class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, -1));
        
        for(auto &w : walls)
            vis[w[0]][w[1]] = 0;
        
        for(auto &g : guards)
            vis[g[0]][g[1]] = 1;
        
        // left to right and right to left
        for(int i = 0; i < m; i++){
            bool guarded = false;
            for(int j = 0; j < n; j++){
                if(vis[i][j] == 1) guarded = true;
                else if(vis[i][j] == 0) guarded = false;
                else if(guarded) vis[i][j] = 2;
            }
            guarded = false;
            for(int j = n-1; j >= 0; j--){
                if(vis[i][j] == 1) guarded = true;
                else if(vis[i][j] == 0) guarded = false;
                else if(guarded) vis[i][j] = 2;
            }
        }
        
        // top to bottom and bottom to top
        for(int j = 0; j < n; j++){
            bool guarded = false;
            for(int i = 0; i < m; i++){
                if(vis[i][j] == 1) guarded = true;
                else if(vis[i][j] == 0) guarded = false;
                else if(guarded) vis[i][j] = 2;
            }
            guarded = false;
            for(int i = m-1; i >= 0; i--){
                if(vis[i][j] == 1) guarded = true;
                else if(vis[i][j] == 0) guarded = false;
                else if(guarded) vis[i][j] = 2;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] == -1) ans++;
            }
        }
        return ans;
    }
};
