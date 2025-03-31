class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> ans_vec(n, 0), visited(n, 0), distance(n, 0);
        vector<vector<int>> vec(n);
        map<pair<int, int>, int> distances;
        queue<pair<int, int>> q;
        int m = edges.size(), ans = INT_MIN, curr_node, curr_distance, q_size, min_dist = INT_MAX;
        for(int i = 0; i < m; i++){
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
            distances[{edges[i][0], edges[i][1]}] = edges[i][2];
            distances[{edges[i][1], edges[i][0]}] = edges[i][2];
        }
        for(int i = 0; i < n; i++){
            q.push({i, 0});
            while(!q.empty()){
                q_size = q.size();
                for(int j = 0; j < q_size; j++){
                    curr_node = q.front().first;
                    curr_distance = q.front().second;
                    q.pop();
                    visited[curr_node] = 1;
                    for(int k = 0; k < vec[curr_node].size(); k++){
                        if(!visited[vec[curr_node][k]] && curr_distance + distances[{curr_node, vec[curr_node][k]}] <= distanceThreshold){
                            q.push({vec[curr_node][k], curr_distance + distances[{curr_node, vec[curr_node][k]}]});
                            distance[vec[curr_node][k]] = curr_distance + distances[{curr_node, vec[curr_node][k]}];
                        }else if(visited[vec[curr_node][k]] && curr_distance + distances[{curr_node, vec[curr_node][k]}] < distance[vec[curr_node][k]]){
                            q.push({vec[curr_node][k], curr_distance + distances[{curr_node, vec[curr_node][k]}]});
                            distance[vec[curr_node][k]] = curr_distance + distances[{curr_node, vec[curr_node][k]}];
                        }
                    }
                }
            }
            for(int j = 0; j < n; j++){
                if(visited[j])
                    ans_vec[i]++, visited[j] = 0, distance[j] = INT_MAX;
            }
            ans_vec[i]--;
        }
        for(int i = 0; i < n; i++)
            min_dist = min(min_dist, ans_vec[i]);
        cout << min_dist << endl;
        for(int i = 0; i < n; i++)
            if(min_dist==ans_vec[i])
                ans = i;
        return ans;
    }
};