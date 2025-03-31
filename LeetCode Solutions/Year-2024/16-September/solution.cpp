class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<vector<int>> t;
        vector<int> v;
        for(auto s : timePoints){
            v = {stoi(s.substr(0, 2)), stoi(s.substr(3, 2))};
            t.push_back(v);
            t.push_back({v[0]+24, v[1]});
        }
        sort(t.begin(), t.end());
        int ans = INT_MAX, n = t.size();
        for(int i = 1; i < n; i++){
            ans = min(ans, 60*(t[i][0]-t[i-1][0]) + (t[i][1]-t[i-1][1]));
        }
        return ans;
    }
};