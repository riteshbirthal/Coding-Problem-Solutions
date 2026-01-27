class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int k, node;
        map<pair<int, int>, int> wts;
        vector<vector<int>> vec(n);
        for(auto& e : edges){
            wts[{e[0], e[1]}] = wts.find({e[0], e[1]})==wts.end() ? e[2] : min(e[2], wts[{e[0], e[1]}]);
            wts[{e[1], e[0]}] = wts.find({e[1], e[0]})==wts.end() ? 2*e[2] : min(2*e[2], wts[{e[1], e[0]}]);
            vec[e[0]].push_back(e[1]), vec[e[1]].push_back(e[0]);
        }
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(q.size()){
            k = q.size();
            while(k--){
                node = q.front(), q.pop();
                for(int x : vec[node]){
                    if(dist[x] > dist[node] + wts[{node, x}]){
                        dist[x] = dist[node] + wts[{node, x}];
                        q.push(x);
                    }
                }
            }
        }
        return dist[n-1]==INT_MAX ? -1 : dist[n-1];
    }
};
