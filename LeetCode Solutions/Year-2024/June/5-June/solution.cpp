class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size(), mn;
        vector<string> ans;
        vector<vector<int>> vec(n, vector<int>(26, 0));
        string st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].size(); j++){
                vec[i][words[i][j]-'a']++;
            }
        }
        for(int i = 0; i < 26; i++){
            mn = INT_MAX;
            for(int j = 0; j < n; j++){
                mn = min(mn, vec[j][i]);
            }
            st = "", st.push_back('a'+i);
            for(int j = 0; j < mn; j++) ans.push_back(st);
        }
        return ans;
    }
};