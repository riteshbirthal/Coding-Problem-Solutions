class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans = 0, ptr1 = 0, ptr2 = 0;
        while(ptr1 < s.size() && ptr2 < t.size()){
            if(s[ptr1]==t[ptr2]) ptr2++, ans++;
            ptr1++;
        }
        ans = t.size() - ans;
        return ans;
    }
};