class Solution {
    public:
        int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
            unordered_map<int, int> row, column;
            map<int, vector<int>> mp;
            int n = mat.size(), m = mat[0].size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    mp[mat[i][j]] = {i, j};
                }
            }
            int k = arr.size(), rs, cs; //current rowsize(rs), columnsize(cs)
            for(int i = 0; i < k; i++){
                rs = row.find(mp[arr[i]][0])==row.end() ? 0 : row[mp[arr[i]][0]];
                cs = column.find(mp[arr[i]][1])==column.end() ? 0 : column[mp[arr[i]][1]];
                if(rs+1==m || cs+1==n)
                    return i;
                row[mp[arr[i]][0]] = rs + 1;
                column[mp[arr[i]][1]] = cs + 1;
            }
            return k;
        }
    };