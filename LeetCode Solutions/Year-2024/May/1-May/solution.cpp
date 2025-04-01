class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        int idx = 0;
        while(idx<word.size() && word[idx]!=ch) idx++;
        if(idx==word.size()) return word;
        for(int i = idx; i >=0; i--) ans += word[i];
        while(idx+1<word.size()) ans += word[idx+1], idx++;
        return ans;
    }
};