class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        set<int> st;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < n-k+1; i++){
            vector<int> vec;
            for(int j = 0; j < m-k+1; j++){
                st.clear();
                for(int l = i; l < i+k; l++){
                    for(int m = j; m < j+k; m++){
                        st.insert(grid[l][m]);
                    }
                }
                vector<int> v(st.begin(), st.end());
                int s = v.size(), minDiff = INT_MAX;
                for(int x = 1; x < s; x++)
                    minDiff = min(minDiff, v[x]-v[x-1]);
                vec.push_back(minDiff==INT_MAX ? 0 : minDiff);
            }
            res.push_back(vec);
        }
        return res;
    }
};
