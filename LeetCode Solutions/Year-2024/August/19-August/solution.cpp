class Solution {
public:
    int minSteps(int n) {
        vector<int> vec(n+1, INT_MAX);
        vec[1] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 2; i*j <= n; j++){
                vec[i*j] = vec[i] + j;
            }
        }
        return vec[n];
    }
};