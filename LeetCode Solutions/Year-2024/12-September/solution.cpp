class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size(), ans = 0, flag, siz = allowed.size();
        unordered_set<char> ald;
        for(int i = 0; i < siz; i++)
            ald.insert(allowed[i]);
        for(int i = 0; i < n; i++){
            siz = words[i].size(), flag = 1;
            for(int j = 0; j < siz; j++)
                if(ald.find(words[i][j])==ald.end())
                    flag = 0;
            ans += flag;
        }
        return ans;
    }
};