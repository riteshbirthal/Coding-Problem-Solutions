class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> vec(n + 1);
        int m = edges.size(), k, curr_node, curr_time, ans = INT_MAX,
            mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<int> visited(n + 1, 0), visit_time(n+1, INT_MIN), ans_time;
        while (!q.empty()) {
            k = q.size();
            for (int i = 0; i < k; i++) {
                curr_node = q.front().first;
                curr_time = q.front().second;
                visited[curr_node]++;
                q.pop();
                for (int j = 0; j < vec[curr_node].size(); j++) {
                    if (visited[vec[curr_node][j]] < 2 &&
                        (curr_time / change) % 2 == 0) {
                        if (vec[curr_node][j] != n && visit_time[vec[curr_node][j]]<curr_time + time)
                            q.push({vec[curr_node][j], curr_time + time}), visit_time[vec[curr_node][j]] = curr_time + time;
                        else if(vec[curr_node][j] == n){
                            if(!ans_time.size() || (ans_time[ans_time.size()-1]<curr_time+time)){
                                ans_time.push_back(curr_time + time);
                                q.push({vec[curr_node][j], curr_time + time});
                            }
                        }
                    } else if (visited[vec[curr_node][j]] < 2) {
                        q.push({curr_node,
                                curr_time + change - curr_time % change});
                        visited[curr_node]--;
                    }
                }
            }
        }
        sort(ans_time.begin(), ans_time.end());
        ans = ans_time[1];
        return ans;
    }
};