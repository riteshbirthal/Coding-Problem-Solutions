class Solution {
public:
    void func(string s, int n, string st, map<string, int>& mp, vector<string>& vec, vector<string> & vec2){
        if(n==s.size()){
            if(mp.find(st)!=mp.end()){
                string temp = "";
                for(int i = 0; i < vec2.size(); i++) temp += vec2[i] + " ";
                temp += st;
                vec.push_back(temp);
            }
            return ;
        }
        st += s[n];
        if(mp.find(st)!=mp.end()){
            vec2.push_back(st);
            func(s, n+1, "", mp, vec, vec2);
            vec2.pop_back();
        }
        func(s, n+1, st, mp, vec, vec2);
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, int> mp;
        for(int i = 0; i < wordDict.size(); i++) mp[wordDict[i]]++;
        vector<string> vec, vec2;
        func(s, 0, "", mp, vec, vec2);
        return vec;
    }
};