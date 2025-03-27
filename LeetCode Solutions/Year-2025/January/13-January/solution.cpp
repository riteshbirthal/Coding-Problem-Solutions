class Solution {
    public:
        int minimumLength(string s) {
            vector<int> vec(26, 0);
            int res = 0;
            for(char ch : s)
                vec[ch-'a']++;
            for(int i = 0; i < 26; i++)
                vec[i] && vec[i]%2==0 ? res += 2 : (vec[i] ? res += 1 : res);
            return res;
        }
    };