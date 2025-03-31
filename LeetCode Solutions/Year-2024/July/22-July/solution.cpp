class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> vec;
        for(int i = 0; i < n; i++)
            vec.push_back({heights[i], names[i]});
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        for(int i = 0; i < n; i++)
            names[i] = vec[i].second;
        return names;
    }
};