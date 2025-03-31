class Solution {
public:
    int dfs1(vector<vector<int>>& edges, int node, vector<int>& visited, map<int, int>& mp){
        if(mp.find(node) != mp.end()) return 0;
        mp[node]++;
        int ans = 1;
        for(int i = 0; i < edges[node].size(); i++){
            if(!visited[edges[node][i]])
                if(!dfs1(edges, edges[node][i], visited, mp))
                    return 0;
        }
        visited[node] = 1;
        mp.erase(node);
        return ans;
    }
    int check_cycle(vector<vector<int>>& edges, int n){
        map<int, int> mp;
        vector<int> visited(n+1, 0);
        for(int i = 1; i < n+1; i++){
            if(!visited[i])
                if(!dfs1(edges, i, visited, mp))
                    return 1;
        }
        return 0;
    }
    void dfs(vector<vector<int>>& edges, int node, vector<int>& visited, stack<int>& st){
        visited[node] = 1;
        for(int i = 0; i < edges[node].size(); i++){
            if(!visited[edges[node][i]])
                dfs(edges, edges[node][i], visited, st);
        }
        st.push(node);
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> vec(k, vector<int>(k, 0)), rowE(k+1), columnE(k+1);
        vector<int> visited(k+1, 0), row(k, 0), column(k, 0);
        stack<int> st;
        int n = rowConditions.size(), idx;
        for(int i = 0; i < n; i++)
            rowE[rowConditions[i][0]].push_back(rowConditions[i][1]);
        n = colConditions.size();
        for(int i = 0; i < n; i++)
            columnE[colConditions[i][0]].push_back(colConditions[i][1]);
        if(check_cycle(rowE, k) || check_cycle(columnE, k)) return {};
        for(int i = 1; i < k+1; i++)
            if(!visited[i])
                dfs(rowE, i, visited, st);
        idx = 0;
        while(!st.empty()){
            visited[idx+1] = 0;
            row[st.top()-1] = idx;
            st.pop();
            idx++;
        }
        for(int i = 1; i < k+1; i++)
            if(!visited[i])
                dfs(columnE, i, visited, st);
        idx = 0;
        while(!st.empty()){
            cout << st.top() << " ";
            column[st.top()-1] = idx;
            st.pop();
            idx++;
        }
        for(int i = 0; i < k; i++){
            vec[row[i]][column[i]] = i+1;
        }
        return vec;
    }
};