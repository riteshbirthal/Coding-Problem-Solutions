class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n = s.size(), flag;
        for(int i = 0; i < n; i++){
            flag = 1;
            for(int j = i; j < i+n && flag; j++){
                if(s[j%n]!=goal[j-i]) flag = 0;
            }
            if(flag) return true;
        }
        return false;
    }
};