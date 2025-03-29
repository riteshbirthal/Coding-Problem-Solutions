class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vec(n);
        vector<int> discarded(n, 1);
        for(int i = 0; i < edges.size(); i++){
            vec[edges[i][0]].push_back(edges[i][1]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < vec[i].size(); j++){
                discarded[vec[i][j]] = 0;
            }
        }
        int count = 0, ans = -1;
        for(int i = 0; i < n; i++){
            if(discarded[i])
                count++, ans = i;
        }
        if(count>1)
            return -1;
        return ans;
    }
};