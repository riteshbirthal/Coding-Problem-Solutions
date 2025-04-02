class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<vector<int>> vec1(200), vec2(200);
        for(int i = 0; i < s.size(); i++){
            vec1[s[i]].push_back(i);
            vec2[t[i]].push_back(i);
        }
        for(int i = 0; i < s.size(); i++){
            if(vec1[s[i]]!=vec2[t[i]]) return false;
        }
        return true;
    }
};