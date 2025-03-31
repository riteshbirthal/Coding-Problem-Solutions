class Solution {
public:
    vector<int> parent;
    void make_set(int v){
        parent[v] = v;
    }
    
    int find_set(int v){
        if(v==parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void merge_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b)
            parent[b] = a;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> alice, bob, both, alice_tr(n), bob_tr(n);
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0]==1) 
                alice.push_back({edges[i][1]-1, edges[i][2]-1}), alice_tr[edges[i][1]-1].push_back(edges[i][2]-1), alice_tr[edges[i][2]-1].push_back(edges[i][1]-1);
            else if(edges[i][0]==2) 
                bob.push_back({edges[i][1]-1, edges[i][2]-1}), bob_tr[edges[i][1]-1].push_back(edges[i][2]-1), bob_tr[edges[i][2]-1].push_back(edges[i][1]-1);
            else 
                both.push_back({edges[i][1]-1, edges[i][2]-1}), alice_tr[edges[i][1]-1].push_back(edges[i][2]-1), alice_tr[edges[i][2]-1].push_back(edges[i][1]-1), 
                                                                        bob_tr[edges[i][1]-1].push_back(edges[i][2]-1), bob_tr[edges[i][2]-1].push_back(edges[i][1]-1);
        }
        int ans = 0, flag_alice = 1, flag_bob = 1, size;
        vector<int> temp(n);
        for(int i = 0; i < n; i++) temp[i] = i;
        parent = temp;
        for(int i = 0; i < both.size(); i++){
            if(find_set(both[i][0]) == find_set(both[i][1]))
                ans++;
            else
                merge_set(both[i][0], both[i][1]);
        }
        temp = parent;
        for(int i = 0; i < alice.size(); i++){
            if(find_set(alice[i][0]) == find_set(alice[i][1]))
                ans++;
            else
                merge_set(alice[i][0], alice[i][1]);
        }
        parent = temp;
        for(int i = 0; i < bob.size(); i++){
            if(find_set(bob[i][0]) == find_set(bob[i][1]))
                ans++;
            else
                merge_set(bob[i][0], bob[i][1]);
        }
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                for(int j = 0; j < alice_tr[q.front()].size(); j++){
                    if(!visited[alice_tr[q.front()][j]])
                        q.push(alice_tr[q.front()][j]), visited[alice_tr[q.front()][j]] = 1;
                }
                q.pop();
            }
        }
        for(int i = 0; i < n; i++)
            if(!visited[i])
                flag_alice = 0;
        visited = vector<int>(n, 0);
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                for(int j = 0; j < bob_tr[q.front()].size(); j++){
                    if(!visited[bob_tr[q.front()][j]])
                        q.push(bob_tr[q.front()][j]), visited[bob_tr[q.front()][j]] = 1;
                }
                q.pop();
            }
        }
        for(int i = 0; i < n; i++)
            if(!visited[i])
                flag_bob = 0;
        if(flag_alice && flag_bob)
            return ans;
        return -1;
    }
};