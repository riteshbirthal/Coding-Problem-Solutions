class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        vector<set<char>> vec12(26), vec21(26);
        bool res = true;
        int n = s1.size();
        for(int i = 0; i < n; i++){
            vec21[s1[i]-'a'].insert(s2[i]);
            vec12[s2[i]-'a'].insert(s1[i]);
            if(vec12[s2[i]-'a'].size()>1 || vec21[s1[i]-'a'].size()>1)
                res = false;
        }
        return res;
    }
};
