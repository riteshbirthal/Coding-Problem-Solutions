class Solution {
public:
    void visitPowerStations(vector<vector<int>>& edges, int node, vector<int>& visited, int group, map<int, pair<set<int>, set<int>>>& groups){
        visited[node] = group;
        groups[group].first.insert(node);
        for(int x : edges[node]){
            if(visited[x]==-1){
                visitPowerStations(edges, x, visited, group, groups);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> res, visited(c, -1);
        vector<vector<int>> edges(c);
        map<int, pair<set<int>, set<int>>> groups;
        for(auto c : connections)
            edges[c[0]-1].push_back(c[1]-1), edges[c[1]-1].push_back(c[0]-1);
        int group_number = 0, group;
        for(int i = 0; i < c; i++)
            if(visited[i]==-1)
                visitPowerStations(edges, i, visited, group_number, groups), group_number++;
        for(auto q : queries){
            if(q[0]==1){
                group = visited[q[1]-1];
                if(groups[group].first.size()==0)
                    res.push_back(-1);
                else
                    groups[group].first.find(q[1]-1)!=groups[group].first.end() ? res.push_back(q[1]) : res.push_back(*(groups[group].first.begin()) + 1);
            }else{
                group = visited[q[1]-1];
                groups[group].first.erase(q[1]-1);
                groups[group].second.insert(q[1]-1);
            }
        }
        return res;
    }
};
