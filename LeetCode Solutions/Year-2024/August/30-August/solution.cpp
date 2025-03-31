class Solution {
public:
    int min_distance(vector<vector<int>>& edges, int src, int dest, int n, vector<vector<int>> & w){
        vector<int> visited(n, 0), dist(n, INT_MAX);
        int k, node;
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        visited[src] = 1;
        while(!q.empty()){
            k = q.size();
            while(k--){
                node = q.front(), q.pop();
                for(auto x : edges[node]){
                    if(w[node][x]!=-1 && (!visited[x] || (dist[node] + w[node][x] < dist[x]))){
                        dist[x] = dist[node] + w[node][x];
                        visited[x] = 1;
                        q.push(x);
                    }
                }
            }
        }
        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> vec(n), ans, missed_weights, actual_edges, w(n, vector<int>(n, -1)), temp_w = w;
        for(auto x : edges){
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);
            actual_edges.push_back({x[0], x[1]});
            if(x[2]==-1)
                missed_weights.push_back({x[0], x[1]});
            else
                w[x[0]][x[1]] = x[2], w[x[1]][x[0]] = x[2];
            temp_w[x[0]][x[1]] = max(1, x[2]), temp_w[x[1]][x[0]] = max(1, x[2]);  
        }

        long long min_dist, rem_dist, dist_sa, dist_bd, dist_ab, dist_sd, diff;
        min_dist = min_distance(vec, source, destination, n, w);
        if(min_dist<target)
            return ans;
        if(min_dist==target){
            for(auto y : actual_edges){
                if(w[y[0]][y[1]]==-1)
                    ans.push_back({y[0], y[1], target});
                else
                    ans.push_back({y[0], y[1], w[y[0]][y[1]]});
            }
            return ans;
        }
        min_dist = min_distance(vec, source, destination, n, temp_w);
        if(min_dist>target)
            return ans;
        for(auto x : missed_weights){
            // Node a --> b     where    a = x[0], b = x[1]
            dist_ab = min_distance(vec, x[0], x[1], n, w);
            dist_sd = min_distance(vec, source, destination, n, w);
            // case 1  src-->a  + a-->b + b-->dest
            dist_sa = min_distance(vec, source, x[0], n, w);
            dist_bd = min_distance(vec, x[1], destination, n, w);
            diff = dist_sd - dist_sa - dist_bd;
            if(diff>0 && dist_sa + dist_bd < target && target - (dist_sa + dist_bd)<dist_ab){
                diff = target - (dist_sa + dist_bd);
                w[x[0]][x[1]] = diff, w[x[1]][x[0]] = diff;
                min_dist = min_distance(vec, source, destination, n, w);
                if(min_dist==target){
                    for(auto y : actual_edges){
                        if(w[y[0]][y[1]]==-1)
                            ans.push_back({y[0], y[1], target});
                        else
                            ans.push_back({y[0], y[1], w[y[0]][y[1]]});
                    }
                    return ans;
                }
                // w[x[0]][x[1]] = -1, w[x[1]][x[0]] = -1;
            }

            // case 2  src-->b  + a-->b + a-->dest
            dist_sa = min_distance(vec, source, x[1], n, w);
            dist_bd = min_distance(vec, x[0], destination, n, w);
            diff = dist_sd - dist_sa - dist_bd;
            if(diff>0 && dist_sa + dist_bd < target && target - (dist_sa + dist_bd)<dist_ab){
                diff = target - (dist_sa + dist_bd);
                w[x[0]][x[1]] = diff, w[x[1]][x[0]] = diff;
                min_dist = min_distance(vec, source, destination, n, w);
                if(min_dist==target){
                    for(auto y : actual_edges){
                        if(w[y[0]][y[1]]==-1)
                            ans.push_back({y[0], y[1], target});
                        else
                            ans.push_back({y[0], y[1], w[y[0]][y[1]]});
                    }
                    return ans;
                }
                // w[x[0]][x[1]] = -1, w[x[1]][x[0]] = -1;
            }
            w[x[0]][x[1]] = 1, w[x[1]][x[0]] = 1;
        }
        return ans;
    }
};