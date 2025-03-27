class Solution {
    public:
        bool isBipartite(vector<vector<int>>& vec){
            set<vector<int>> edges;
            int n = vec.size(), isRed = 1, k, node;
            for(int i = 0; i < n; i++){
                for(int a : vec[i]){
                    edges.insert({i, a});
                    edges.insert({a, i});
                }
            }
            vector<int> visited(n, 0), red, blue;
            queue<int> q;
            for(int i = 0; i < n; i++){
                if(visited[i])
                    continue;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    k = q.size();
                    for(int j = 0; j < k; j++){
                        node = q.front(), q.pop();
                        isRed ? red.push_back(node) : blue.push_back(node);
                        for(int child : vec[node]){
                            if(!visited[child]){
                                visited[child] = 1;
                                q.push(child);
                            }
                        }
                    }
                    isRed = !isRed;
                }
            }
            n = red.size();
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(edges.find({red[i], red[j]})!=edges.end())
                        return false;
                }
            }
            n = blue.size();
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(edges.find({blue[i], blue[j]})!=edges.end())
                        return false;
                }
            }
            return true;
        }
    
        int bfs(int node, vector<int>& visited, vector<vector<int>>& vec){
            int n = visited.size(), depth, k, curr, maxDepth = 1;
            vector<int> vis(n, 0);
            queue<int> q;
            q.push(node);
            vis[node] = 1;
            visited[node] = 1;
            while(!q.empty()){
                k = q.size();
                for(int i = 0; i < k; i++){
                    curr = q.front(); q.pop();
                    for(int child : vec[curr]){
                        if(!vis[child]){
                            vis[child] = 1, visited[child] = 1;
                            q.push(child);
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                if(!vis[i])
                    continue;
                q.push(i);
                vector<int> v(n, 0);
                v[i] = 1; depth = 0;
                while(!q.empty()){
                    k = q.size();
                    for(int i = 0; i < k; i++){
                        curr = q.front(), q.pop();
                        for(int child : vec[curr]){
                            if(!v[child]){
                                v[child] = 1;
                                q.push(child);
                            }
                        }
                    }
                    depth += 1;
                }
                maxDepth = max(maxDepth, depth);
            }
            return maxDepth;
        }
    
        int magnificentSets(int n, vector<vector<int>>& edges) {
            vector<vector<int>> vec(n);
            for(auto e : edges){
                vec[e[0]-1].push_back(e[1]-1);
                vec[e[1]-1].push_back(e[0]-1);
            }
            if(!isBipartite(vec))
                return -1;
            int res = 0;
            vector<int> visited(n, 0);
            for(int i = 0; i < n; i++){
                if(visited[i])
                    continue;
                res += bfs(i, visited, vec);
            }
            return res;
        }
    };