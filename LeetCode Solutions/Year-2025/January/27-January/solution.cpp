class Solution {
    public:
        unordered_set<int> mergeSet(unordered_set<int> a, unordered_set<int> b){
            for(auto itr = b.begin(); itr != b.end(); itr++){
                a.insert(*itr);
            }
            return a;
        }
    
        unordered_set<int> func(int node, vector<vector<int>>& adj, map<int, unordered_set<int>>& dp){
            unordered_set<int> res, temp;
            if(dp.find(node)!=dp.end()) return dp[node];
            for(int child : adj[node]){
                temp = func(child, adj, dp);
                temp.insert(child);
                res = mergeSet(res, temp);
            }
            return dp[node] = res;
        }
    
        vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
            vector<bool> res;
            vector<vector<int>> adj(numCourses);
            map<int, unordered_set<int>> dp;
            int n = prerequisites.size();
            for(int i = 0; i < n; i++){
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
            // vector<int> visited(numCourses, 0);
            for(int i = 0; i < numCourses; i++){
                if(dp.find(i)==dp.end()){
                    func(i, adj, dp);
                }
            }
            for(auto q : queries){
                res.push_back(dp[q[0]].find(q[1])!=dp[q[0]].end());
            }
            return res;
        }
    };