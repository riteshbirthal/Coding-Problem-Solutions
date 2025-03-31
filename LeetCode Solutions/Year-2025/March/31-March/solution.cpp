class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        long long res = weights[0] + weights[n-1], mn = 0, mx = 0;
        vector<int> vec;
        for(int i = 0; i < n-1; i++)
            vec.push_back(weights[i] + weights[i+1]);
        sort(vec.begin(), vec.end());
        for(int i = 0; i < k-1; i++){
            mn += vec[i];
            mx += vec[n-2-i];
        }
        res = mx - mn;
        return res;
    }
};