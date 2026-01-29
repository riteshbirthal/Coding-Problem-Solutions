class Solution {
public:
    long long func(int src, int dest, vector<vector<int>> & vec, vector<vector<int>>& cc){
        if(src==dest) return 0;
        long long ans = cc[src][dest];
        queue<pair<int, int>> q;
        vector<int> visited(26, 0), dist(26, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i < 26; i++){
            dist[i] = cc[src][i];
        }
        q.push({src, 0});
        int k, curr, cost;
        while(!q.empty()){
            k = q.size();
            for(int i = 0; i < k; i++){
                curr = q.front().first;
                cost = q.front().second;
                q.pop();
                visited[curr] = 1;
                for(int j = 0; j < vec[curr].size(); j++){
                    if(!visited[vec[curr][j]] && cc[curr][vec[curr][j]]!=INT_MAX){
                        dist[vec[curr][j]] = min(dist[vec[curr][j]], cost + cc[curr][vec[curr][j]]);
                        q.push({vec[curr][j], dist[vec[curr][j]]});
                    }else if(cc[curr][vec[curr][j]]!=INT_MAX && cost + cc[curr][vec[curr][j]] < dist[vec[curr][j]]){
                        dist[vec[curr][j]] = min(dist[vec[curr][j]], cost + cc[curr][vec[curr][j]]);
                        q.push({vec[curr][j], dist[vec[curr][j]]});
                    }
                }
            }
        }
        for(int i = 0; i < 26; i++)
            cc[src][i] = dist[i];
        ans = dist[dest];
        return ans;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.size(), m = cost.size();
        vector<vector<int>> vec(26), cost_vec(26, vector<int>(26, INT_MAX));
        map<pair<char, char>, int> change_cost;
        for(int i = 0; i < m; i++){
            if(cost_vec[original[i]-'a'][changed[i]-'a']==INT_MAX)
                vec[original[i]-'a'].push_back(changed[i]-'a');
            cost_vec[original[i]-'a'][changed[i]-'a'] = min(cost_vec[original[i]-'a'][changed[i]-'a'], cost[i]);
        }
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                cost_vec[i][j] = func(i, j, vec, cost_vec);
            }
        }
        long long ans = 0, cost_;
        pair<char, char> pr;
        for(int i = 0; i < n; i++){
            cost_ = cost_vec[source[i]-'a'][target[i]-'a'];
            if(cost_==INT_MAX)
                return -1;
            else
                ans += cost_;
        }
        return ans;
    }
};
