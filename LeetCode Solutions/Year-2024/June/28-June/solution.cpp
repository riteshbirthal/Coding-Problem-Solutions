class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> vec(n, 0);
        for(int i = 0; i < roads.size(); i++)
            vec[roads[i][0]]++, vec[roads[i][1]]++;
        sort(vec.begin(), vec.end());
        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += (i+1)*vec[i];
        return ans;
    }
};