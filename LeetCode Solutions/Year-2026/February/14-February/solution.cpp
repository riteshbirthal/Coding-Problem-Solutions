class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double res = 0;
        vector<vector<double>> glasses(query_row+1);
        for(int i = 0; i < query_row+1; i++)
            for(int j = 0; j < i+1; j++)
                glasses[i].push_back((double)0.0);
        glasses[0][0] = poured;
        for(int i = 0; i < query_row; i++){
            for(int j = 0; j < i+1; j++){
                glasses[i+1][j] += max((double)0, (glasses[i][j]-1)/2.0);
                glasses[i+1][j+1] += max((double)0, (glasses[i][j]-1)/2.0);
            }
        }
        res = glasses[query_row][query_glass]>1 ? 1 : glasses[query_row][query_glass];
        return res;
    }
};
