class Solution {
    public:
        int dfs(int node, int parent, int k, vector<vector<int>>& vec, vector<long long>& val){
            int ans = 0;
            for(auto& child : vec[node]){
                if(child!=parent){
                    ans += dfs(child, node, k, vec, val);
                    val[node] += val[child];
                    if(val[child]%k==0){
                        ans++;
                    }
                }
            }
            return ans;
        }
        int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
            vector<vector<int>> vec(n+1);
            for(auto& edge: edges){
                vec[edge[0]].push_back(edge[1]);
                vec[edge[1]].push_back(edge[0]);
            }
            vector<long long> val;
            for(long long x : values)
                val.push_back(x);
            int ans = 1;
            ans += dfs(0, -1, k, vec, val);
            return ans;
        }
    };