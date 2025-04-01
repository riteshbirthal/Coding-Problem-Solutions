class Solution {
public:
    int func(vector<string>& words, int n, vector<int>& vec, vector<int>& score){
        if(n==0) return 0;
        vector<int> temp(26, 0);
        for(int i = 0; i < words[n-1].size(); i++) temp[words[n-1][i]-'a']++;
        bool flag = true;
        for(int i = 0; i < 26; i++) if(vec[i]<temp[i]) flag = false;
        if(flag){
            int score_ = 0, ans1 = 0, ans2 = 0;
            for(int i = 0; i < words[n-1].size(); i++) score_ += score[words[n-1][i]-'a'];
            for(int i = 0; i < 26; i++) vec[i] -= temp[i];
            ans1 = score_ + func(words, n-1, vec, score);
            for(int i = 0; i < 26; i++) vec[i] += temp[i];
            ans2 = func(words, n-1, vec, score);
            return max(ans1, ans2);
        }
        return func(words, n-1, vec, score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int> vec(26, 0);
        for(int i = 0; i < letters.size(); i++) vec[letters[i]-'a']++;
        return func(words, n, vec, score);
    }
};