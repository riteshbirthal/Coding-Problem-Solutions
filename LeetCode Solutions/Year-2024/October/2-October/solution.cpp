class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr, ans;
        sort(v.begin(), v.end());
        unordered_map<int, int> u;
        int rank = 1, n = v.size();
        for(int i = 0; i < n; i++){
            if(!i || v[i]!=v[i-1])
                u[v[i]] = rank, rank++;
        }
        for(auto x : arr)
            ans.push_back(u[x]);
        return ans;
    }
};