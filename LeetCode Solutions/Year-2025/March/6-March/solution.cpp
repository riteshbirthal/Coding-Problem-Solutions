class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<int> res = {0, 0}, count(n*n+1, 0);
            for(vector<int> v : grid){
                for(int e : v){
                    count[e]++;
                }
            }
            for(int i = 1; i <= n*n; i++){
                if(count[i]==0)
                    res[1] = i;
                else if(count[i]==2)
                    res[0] = i;
            }
            return res;
        }
    };