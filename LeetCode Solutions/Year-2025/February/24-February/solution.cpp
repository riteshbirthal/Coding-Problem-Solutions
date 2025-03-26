class Solution {
    public:
        void dfs(vector<vector<int>>& vec, int node, int idx, vector<int>& visited, unordered_map<int, int>& mp){
            visited[node] = idx;
            if(node==0){
                int n = visited.size();
                for(int i = 0; i < n; i++){
                    if(visited[i]!=-1)
                        mp[i] = visited[i];
                }
                visited[node] = -1;
                return ;
            }
            for(int child : vec[node]){
                if(visited[child]==-1){
                    dfs(vec, child, idx+1, visited, mp);
                }
            }
            visited[node] = -1;
            return ;
        }
    
        int dfs2(vector<vector<int>>& vec, int node, int idx, vector<int>& visited, unordered_map<int, int>& mp, vector<int>& amount){
            int res = INT_MIN, cost = (mp.find(node)!=mp.end() && mp[node]==idx) ? amount[node]/2 : ((mp.find(node)==mp.end() || mp[node]>idx) ? amount[node] : 0);
            bool isLeaf = true;
            visited[node] = idx;
            for(int child : vec[node]){
                if(visited[child]==-1)
                    res = max(res, cost + dfs2(vec, child, idx+1, visited, mp, amount)), isLeaf = false;
            }
            visited[node] = -1;
            return isLeaf ? cost : res;
        }
    
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = edges.size() + 1, res = INT_MIN;
            vector<vector<int>> vec(n);
            for(auto v : edges){
                vec[v[0]].push_back(v[1]);
                vec[v[1]].push_back(v[0]);
            }
            vector<int> visited(n, -1);
            unordered_map<int, int> mp;
            dfs(vec, bob, 0, visited, mp);
            res = dfs2(vec, 0, 0, visited, mp, amount);
            return res;
        }
    };