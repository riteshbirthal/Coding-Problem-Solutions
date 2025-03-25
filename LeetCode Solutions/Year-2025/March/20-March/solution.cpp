class Solution {
    public:
        int findAncestor(vector<vector<int>>& vec, int node, int anc, vector<int>& visited, vector<int>& ancestor, map<vector<int>, int>& mp){
            int res = INT_MAX;
            queue<int> q;
            q.push(node);
            visited[node] = 1;
            while(!q.empty()){
                node = q.front(), q.pop();
                ancestor[node] = anc;
                for(int child : vec[node]){
                    res &= mp[{child, node}];
                    if(!visited[child]){
                        visited[child] = 1;
                        q.push(child);
                    }
                }
            }
            return res;
        }
    
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            vector<vector<int>> vec(n);
            map<vector<int>, int> mp;
            for(vector<int> e : edges){
                vec[e[0]].push_back(e[1]), vec[e[1]].push_back(e[0]);
                if(mp.find({e[0], e[1]})==mp.end())
                    mp[{e[0], e[1]}] = e[2], mp[{e[1], e[0]}] = e[2];
                else
                    mp[{e[0], e[1]}] &= e[2], mp[{e[1], e[0]}] &= e[2];
            }
            vector<int> visited(n, 0), ancestor(n, -1), res, mnW(n, INT_MAX);
    
            for(int i = 0; i < n; i++)
                if(!visited[i])
                    mnW[i] = findAncestor(vec, i, i, visited, ancestor, mp);
    
            for(vector<int> q : query)
                ancestor[q[0]]!=ancestor[q[1]] ? res.push_back(-1) : res.push_back(mnW[ancestor[q[0]]]);
    
            return res;
        }
    };