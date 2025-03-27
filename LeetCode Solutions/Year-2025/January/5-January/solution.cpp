class Solution {
    public:
        char shiftChar(char ch, int shift){
            return 'a' + (ch - 'a' + shift%26 + 26)%26;
        }
    
        string shiftingLetters(string s, vector<vector<int>>& shifts) {
            int n = s.size(), shift = 0;
            vector<int> vec(n+1, 0);
            for(auto sh : shifts){
                sh[2]==0 ? (vec[sh[0]] -= 1, vec[sh[1]+1] += 1) : (vec[sh[0]] += 1, vec[sh[1]+1] -= 1);
            }
            for(int i = 0; i < n; i++){
                shift = (shift + vec[i]) % 26;
                s[i] = shiftChar(s[i], shift);
            }
            return s;
        }
    };