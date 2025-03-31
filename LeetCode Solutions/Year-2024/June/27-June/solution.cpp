class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = 0;
        for(int i = 0; i < edges.size(); i++) n = max(n, max(edges[i][0], edges[i][1]));
        vector<vector<int>> vec(n+1);
        for(int i = 0; i < edges.size(); i++) vec[edges[i][0]].push_back(edges[i][1]), vec[edges[i][1]].push_back(edges[i][0]);
        for(int i = 0; i < n+1; i++) if(vec[i].size()==n-1) return i;
        return 1;
    }
};