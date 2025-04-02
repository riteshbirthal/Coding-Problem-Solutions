class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> nodes(n);
        for(int i = 0; i < edges.size(); i++){
            nodes[edges[i][0]].push_back(edges[i][1]);
            nodes[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()){
            if(q.front()==destination) return true;
            else{
                for(int i = 0; i < nodes[q.front()].size(); i++){
                    if(visited[nodes[q.front()][i]]==0){
                        q.push(nodes[q.front()][i]);
                        visited[nodes[q.front()][i]] = 1;
                    }
                }
                q.pop();
            }
        }
        return 0;
    }
};