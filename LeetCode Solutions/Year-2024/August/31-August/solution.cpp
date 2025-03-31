class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        map<vector<int>, double> mp;
        vector<vector<int>> vec(n);
        int m = edges.size(), k;
        for(int i = 0; i < m; i++){
            mp[{edges[i][0], edges[i][1]}] = succProb[i];
            mp[{edges[i][1], edges[i][0]}] = succProb[i];
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int, double>> q;
        vector<double> probs(n, 0);
        vector<int> visited(n);
        probs[end_node] = 1;
        q.push({end_node, 1});
        pair<int, double> pr;
        while(!q.empty()){
            k = q.size();
            for(int i = 0; i < k; i++){
                pr = q.front();
                q.pop();
                for(auto x : vec[pr.first]){
                    if(pr.second * mp[{pr.first, x}] > probs[x]){
                        probs[x] = pr.second * mp[{pr.first, x}];
                        q.push({x, probs[x]});
                    }
                }
            }
        }
        return probs[start_node];
    }
};