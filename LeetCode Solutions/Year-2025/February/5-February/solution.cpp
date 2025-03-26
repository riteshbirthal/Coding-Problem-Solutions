class Solution {
    public:
        bool areAlmostEqual(string s1, string s2) {
            vector<int> v1(26, 0), v2(26, 0);
            int n = s1.size(), count = 0;
            for(int i = 0; i < n; i++){
                v1[s1[i]-'a']++, v2[s2[i]-'a']++;
                if(s1[i]!=s2[i]) count++;
            }
            for(int i = 0; i < 26; i++)
                if(v1[i]!=v2[i]) return false;
            if(count>2) return false;
            return true;
        }
    };