class Solution {
    public:
        int maxScore(string s) {
            int n = s.size(), res = 0;
            vector<int> left(n, 0), right(n, 0);
            left[0] = s[0]=='0', right[n-1] = s[n-1]=='1';
            for(int i = 1; i < n; i++){
                left[i] = left[i-1] + (s[i]=='0');
                right[n-i-1] = right[n-i] + (s[n-1-i]=='1');
            }
            for(int i = 1; i < n; i++){
                res = max(res, left[i-1] + right[i]);
            }
            return res;
        }
    };