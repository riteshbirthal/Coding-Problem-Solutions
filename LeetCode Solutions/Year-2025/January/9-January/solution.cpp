class Solution {
    public:
        bool func(string pat, string word){
            if(pat.size()>word.size())
                return false;
            int n = pat.size();
            for(int i = 0; i < n; i++)
                if(pat[i]!=word[i])
                    return false;
            return true;
        }
        int prefixCount(vector<string>& words, string pref) {
            int res = 0;
            for(string word : words){
                if(func(pref, word))
                    res += 1;
            }
            return res;
        }
    };