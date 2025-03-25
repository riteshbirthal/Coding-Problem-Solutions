class Solution {
    public:
        long long getShortestTime(vector<vector<int>>& vec, map<vector<int>, int>& times, vector<long long>& dp){
            int n = vec.size(), k;
            queue<pair<int, long long>> q;
            pair<int, long long> pr;
            q.push({0, 0});
            dp[0] = 0;
            while(!q.empty()){
                k = q.size();
                while(k--){
                    pr = q.front(), q.pop();
                    for(int node : vec[pr.first]){
                        if(dp[node]>pr.second + times[{pr.first, node}]){
                            dp[node] = pr.second + times[{pr.first, node}];
                            q.push({node, dp[node]});
                        }
                    }
                }
            }
            return dp[n-1];
        }
    
        long long getWays(int node, vector<vector<int>>& vec, vector<long long>& dp, vector<long long>& dp1, map<vector<int>, int>& times){
            if(node==vec.size()-1)
                return 1;
            if(dp1[node]!=-1)
                return dp1[node];
            long long res = 0;
            for(int child : vec[node]){
                if(dp[node] + times[{child, node}]==dp[child]){
                    res += getWays(child, vec, dp, dp1, times);
                }
            }
            return dp1[node] = res%(long long)(1e9+7);
        }
    
        int countPaths(int n, vector<vector<int>>& roads) {
            int res = 0, node;
            long long shortestTime, mod = 1e9+7;
            vector<vector<int>> vec(n);
            vector<long long> dp(n, LONG_MAX), dp1(n, -1), visited(n, 0);
            map<vector<int>, int> times;
            for(vector<int>& r : roads){
                times[{r[0], r[1]}] = r[2], times[{r[1], r[0]}] = r[2];
                vec[r[0]].push_back(r[1]), vec[r[1]].push_back(r[0]);
            }
            shortestTime = getShortestTime(vec, times, dp);
            res = getWays(0, vec, dp, dp1, times)%(long long)(1e9+7);
            return res;
        }
    };