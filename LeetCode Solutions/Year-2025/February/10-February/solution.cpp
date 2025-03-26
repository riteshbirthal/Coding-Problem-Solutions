class Solution {
    public:
        string clearDigits(string s) {
            string res = "";
            for(char c : s)
                (c>='0' && c<='9') ? res.pop_back() : res.push_back(c);
            return res;
        }
    };