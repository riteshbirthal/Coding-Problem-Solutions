class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, temp = 0;
        for(int i = s.size()-1; i >=0; i--){
            if(s[i]!=' ') temp = 1;
            if(temp && s[i]==' '){
                temp = 0;
                break;
            }
            if(temp) ans++;
        }
        return ans;
    }
};