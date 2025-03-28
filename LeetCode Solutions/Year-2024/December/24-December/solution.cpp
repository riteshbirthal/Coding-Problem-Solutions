class Solution {
    public:
        int farthest_node, dia;
        void dfs(int node, vector<vector<int>>& vec, vector<int>& visited,
                 int dist) {
            if (dist > dia)
                dia = dist, farthest_node = node;
            visited[node] = 1;
            for (int i = 0; i < vec[node].size(); i++) {
                if (!visited[vec[node][i]])
                    dfs(vec[node][i], vec, visited, dist + 1);
            }
            visited[node] = 0;
        }
        int diameter(vector<vector<int>>& edges) {
            int ans = 0, n = 0;
            for (int i = 0; i < edges.size(); i++)
                n = max(edges[i][0], edges[i][1]);
            vector<vector<int>> vec(n + 1);
            for (int i = 0; i < edges.size(); i++) {
                vec[edges[i][0]].push_back(edges[i][1]);
                vec[edges[i][1]].push_back(edges[i][0]);
            }
            vector<int> visited(n + 1, 0);
            farthest_node = 0, dia = 0;
            dfs(0, vec, visited, 0);
            dfs(farthest_node, vec, visited, 0);
            return dia;
        }
        int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                      vector<vector<int>>& edges2) {
            int d1 = diameter(edges1), d2 = diameter(edges2);
            return max(1 + (d1 + 1) / 2 + (d2 + 1) / 2, max(d1, d2));
        }
    };