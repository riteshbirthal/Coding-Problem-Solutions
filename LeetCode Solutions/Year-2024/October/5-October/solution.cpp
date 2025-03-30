class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), flag = 1;
        if(n1>n2) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for(int i = 0; i < n1; i++)
            v1[s1[i]-'a']++, v2[s2[i]-'a']++;
        for(int i = 0; i < 26 && flag; i++)
            if(v1[i]!=v2[i]) flag = 0;
        if(flag) return true;
        for(int i = n1; i < n2; i++){
            v2[s2[i-n1]-'a']--, v2[s2[i]-'a']++, flag = 1;
            for(int j = 0; j < 26 && flag; j++)
                if(v1[j]!=v2[j]) flag = 0;
            if(flag) return true;
        }
        return false;
    }
};